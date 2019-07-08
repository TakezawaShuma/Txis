#include "../../pch.h"
#include "GameScene.h"
#include "../DrawManager.h"
#include "../InputManager.h"
#include "../NetworkPart/NetworkClient.h"
#include "../NetworkPart/NetworkManeger.h"
#include "ISceneState.h"



#include "TitleScene/TitleScene.h"
#include "LobbyScene/LobbyScene.h"
#include "PlayScene/PlayScene.h"
#include "ResultScene/ResultScene.h"
#include "LoginScene/LoginScene.h"
#include "../DeviceResources.h"


extern void ExitGame();

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="_effectManager"></param>
GameScene::GameScene(System::EffectManager* _effectManager):m_activeScene(nullptr),m_effectManager(nullptr)
{
	m_effectManager = _effectManager;
}

/// <summary>
/// デストラクタ
/// </summary>
GameScene::~GameScene()
{
	m_effectManager = nullptr;
	delete m_activeScene;
	m_activeScene = nullptr;
}

/// <summary>
/// 初期化
/// </summary>
void GameScene::Start()
{
	ChangeScene(Data::Scenes::SCENETYPE::TITLE);
}

/// <summary>
/// ゲーム更新
/// </summary>
/// <returns></returns>
bool GameScene::Update()
{
	bool ret = true;
	m_timer.Tick([&]()
	{
		ret = Execution(m_timer);
	});
	return ret;
}

/// <summary>
/// ゲーム内容実行
/// </summary>
/// <param name="_timer"></param>
/// <returns></returns>
bool GameScene::Execution(DX::StepTimer const& _timer)
{
	DirectX::Keyboard::State keyState = DirectX::Keyboard::Get().GetState();

	if (keyState.Escape)
	{
		ExitGame();
		return false;
	}
	if (m_activeScene != nullptr) { m_activeScene->Recv(); }
	if (m_activeScene != nullptr) { m_activeScene->Update(_timer); }
	else { return false; }
	return true;
}

/// <summary>
/// ゲームの描画処理
/// </summary>
void GameScene::Draw()
{
	if (m_timer.GetFrameCount() == 0)
	{
		return;
	}

	if (m_activeScene != nullptr)
	{
		m_activeScene->Draw();
	}
}

void GameScene::DrawBegin()
{
	System::DrawManager::GetInstance().Begin();
}

void GameScene::DrawEnd()
{
	System::DrawManager::GetInstance().End();
}

/// <summary>
/// シーン変更
/// </summary>
/// <param name="_nextScene"></param>
void GameScene::ChangeScene(Data::Scenes::SCENETYPE _nextScene)
{
	if (_nextScene != Data::Scenes::SCENETYPE::NON)
	{
		if (m_activeScene != nullptr)
		{
			m_activeScene->End();
			delete m_activeScene;
			m_activeScene = nullptr;
		}
		m_activeScene = SwitchingScene(_nextScene);
		m_activeScene->Start(m_effectManager);
	}
}


/// <summary>
/// シーンをスイッチングする
/// </summary>
/// <param name="_nextScene"></param>
/// <returns></returns>
ISceneState* GameScene::SwitchingScene(Data::Scenes::SCENETYPE _nextScene)
{
	ISceneState* sceneState = nullptr;
	switch (_nextScene)
	{
	case Data::Scenes::SCENETYPE::LOGIN:
		sceneState = new LoginScene(this);
		break;

	case Data::Scenes::SCENETYPE::TITLE:
		////sceneState = new TitleScene(this);
		break;

	case Data::Scenes::SCENETYPE::LOBBY:
		//sceneState = new LobbyScene(this);
		break;

	case Data::Scenes::SCENETYPE::PLAY:
		//sceneState = new PlayScene(this);
		break;

	case Data::Scenes::SCENETYPE::RESULT:
		//sceneState = new ResultScene(this);
		break;

	default:
		sceneState = nullptr;
		break;
	}
	return sceneState;

}


