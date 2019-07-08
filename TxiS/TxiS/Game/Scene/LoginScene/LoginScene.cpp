#include "../../pch.h"
// �V�[�� -----------------------------
#include "LoginScene.h"
#include "../TitleScene/TitleScene.h"
#include "../LobbyScene/LobbyScene.h"
// ------------------------------------
// �ʐM�֌W ---------------------------
#include "../../NetworkPart/NetworkClient.h"
#include "../../NetworkPart/NetworkManeger.h"
// ------------------------------------
// ���̑� -----------------------------
//#include "../PlayScene/Player.h"
// ------------------------------------

using namespace System;

/// <summary>
///	�R���X�g���N�^
/// </summary>
/// <param name="_changeScene"></param>
LoginScene::LoginScene(ISceneChange * _changeScene):m_uiManager(nullptr),m_effect(nullptr)
{
	m_changeScene = _changeScene;
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
LoginScene::~LoginScene()
{
	End();
}

/// <summary>
/// ������
/// </summary>
/// <param name="_effect"></param>
void LoginScene::Start(EffectManager* _effect)
{
	timer = 0;
	m_effect = _effect;
	const char* c = NetworkClient::GetInstance().IP();

	if (m_uiManager == nullptr) m_uiManager = new UIManeger();
	if (m_uiManager != nullptr)	m_uiManager->Start(Data::Scenes::SCENETYPE::LOGIN);
	if (!NetworkClient::GetInstance().Connect(c, PORT)) 
	{ 
		return;
	}

}

/// <summary>
/// �X�V
/// </summary>
/// <param name="_timer"></param>
/// <returns></returns>
bool LoginScene::Update(DX::StepTimer const& _timer)
{
	float time = (float)_timer.GetTotalSeconds();
	time;

	// ���O�C���������ǂ����̏��̎󂯎��
	NetworkManeger::GetInstance().Recv(this);

	m_effect->Update(time, Data::Scenes::SCENETYPE::LOGIN, 0);
	if (m_uiManager != nullptr) m_uiManager->Update();


	// ���O�C�����Ă�����
	if (m_myPacket.socket >= SOCKET_MIN&&m_myPacket.socket<=SOCKET_MAX)
	{
		//���g�̃\�P�b�g��o�^
		NetworkClient::GetInstance().SetMySocket(m_myPacket.socket);
		// �o�^��V�[���؂�ւ�
		m_changeScene->ChangeScene(m_myPacket.scene.nextScene);
		return true;
	}
	else { timer++; }

	// ��莞�ԃ��O�C���ł��Ȃ�������^�C�g���֖߂�
	if (timer > 300)
	{
		m_changeScene->ChangeScene(Data::Scenes::SCENETYPE::TITLE);
	}
	return true;
}

/// <summary>
/// �`��
/// </summary>
void LoginScene::Draw()
{
	m_effect->Render(Data::Scenes::SCENETYPE::LOGIN);
	if (m_uiManager != nullptr)	m_uiManager->Render(UIType::NowConnection, 0);
}

void LoginScene::Recv()
{

}

// ��M
int LoginScene::Reception(char * _data)
{
	_data;
	memcpy(&m_myPacket, _data, sizeof(Data::Pakets::LoginData));

	

	return 0;
}

/// <summary>
/// �I��
/// </summary>
void LoginScene::End()
{
	if (m_effect->TextureListSize() != 0) { m_effect->LostTexture(); }
	m_uiManager->End();
	delete m_uiManager;	m_uiManager = nullptr;
}

