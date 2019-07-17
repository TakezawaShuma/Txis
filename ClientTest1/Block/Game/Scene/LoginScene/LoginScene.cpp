#include "../../pch.h"
// シーン -----------------------------
#include "LoginScene.h"
#include "../TitleScene/TitleScene.h"
#include "../LobbyScene/LobbyScene.h"
// ------------------------------------
// 通信関係 ---------------------------
#include "../../NetworkPart/NetworkClient.h"
#include "../../NetworkPart/NetworkManeger.h"
// ------------------------------------
// その他 -----------------------------
//#include "../PlayScene/Player.h"
// ------------------------------------

using namespace System;

/// <summary>
///	コンストラクタ
/// </summary>
/// <param name="_changeScene"></param>
LoginScene::LoginScene(ISceneChange * _changeScene):m_uiManager(nullptr),m_effect(nullptr)
{
	m_changeScene = _changeScene;
}

/// <summary>
/// デストラクタ
/// </summary>
LoginScene::~LoginScene()
{
	End();
}

/// <summary>
/// 初期化
/// </summary>
/// <param name="_effect"></param>
void LoginScene::Start(EffectManager* _effect)
{
	timer = 0;
	m_dataSize = 0;
	m_loginFlag = false;
	m_effect = _effect;
	const char* c = NetworkClient::GetInstance().IP();

	if (m_uiManager == nullptr) { m_uiManager = new UIManeger(); }
	if (m_uiManager != nullptr) { m_uiManager->Start(Data::Scenes::SCENETYPE::LOGIN); }
	if (!NetworkClient::GetInstance().Connect(c, PORT)) { return; }

}

/// <summary>
/// 更新
/// </summary>
/// <param name="_timer"></param>
/// <returns></returns>
bool LoginScene::Update(DX::StepTimer const& _timer)
{
	float time = (float)_timer.GetTotalSeconds();

	if (m_effect != nullptr) { m_effect->Update(time, Data::Scenes::SCENETYPE::LOGIN, 0); }
	if (m_uiManager != nullptr) { m_uiManager->Update(); }

	// ログイン出来たことを確認出来たらロビーへ移動
	if(m_loginFlag)
	{
		// 登録後シーン切り替え
		m_changeScene->ChangeScene(Data::Scenes::SCENETYPE::LOBBY);
		return true;
	}
	else { timer++; }

	// 一定時間ログインできなかったらタイトルへ戻る
	if (timer > 300) { m_changeScene->ChangeScene(Data::Scenes::SCENETYPE::TITLE); }

	return true;
}

/// <summary>
/// 描画
/// </summary>
void LoginScene::Draw()
{
	m_effect->Render(Data::Scenes::SCENETYPE::LOGIN);
	if (m_uiManager != nullptr)	m_uiManager->Render(UIType::NowConnection, 0);
}

void LoginScene::Recv()
{
	NetworkClient::GetInstance().Recv(m_data, sizeof(m_data), &m_dataSize, this);
}

// 受信
int LoginScene::Reception(char * _data)
{
	_data;
	// 接続したときの自身のパケットを取得
	memcpy(&m_myPacket, _data, sizeof(Data::Pakets::LoginData));

	// ログインしていたら
	if (m_myPacket.socket >= SOCKET_MIN&&m_myPacket.socket <= SOCKET_MAX)
	{
		//自身のソケットを登録
		NetworkClient::GetInstance().SetMySocket(m_myPacket.socket);
		m_loginFlag = true;
	}
	return 0;
}

bool LoginScene::Send()
{
	return false;
}

/// <summary>
/// 終了
/// </summary>
void LoginScene::End()
{
	if (m_effect->TextureListSize() != 0) { m_effect->LostTexture(); }
	if (m_uiManager != nullptr) { m_uiManager->End(); }
	delete m_uiManager;	m_uiManager = nullptr;
}

