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
	m_dataSize = 0;
	m_loginFlag = false;
	m_effect = _effect;
	const char* c = NetworkClient::GetInstance().IP();

	if (m_uiManager == nullptr) { m_uiManager = new UIManeger(); }
	if (m_uiManager != nullptr) { m_uiManager->Start(Data::Scenes::SCENETYPE::LOGIN); }
	if (!NetworkClient::GetInstance().Connect(c, PORT)) { return; }

}

/// <summary>
/// �X�V
/// </summary>
/// <param name="_timer"></param>
/// <returns></returns>
bool LoginScene::Update(DX::StepTimer const& _timer)
{
	float time = (float)_timer.GetTotalSeconds();

	if (m_effect != nullptr) { m_effect->Update(time, Data::Scenes::SCENETYPE::LOGIN, 0); }
	if (m_uiManager != nullptr) { m_uiManager->Update(); }

	// ���O�C���o�������Ƃ��m�F�o�����烍�r�[�ֈړ�
	if(m_loginFlag)
	{
		// �o�^��V�[���؂�ւ�
		m_changeScene->ChangeScene(Data::Scenes::SCENETYPE::LOBBY);
		return true;
	}
	else { timer++; }

	// ��莞�ԃ��O�C���ł��Ȃ�������^�C�g���֖߂�
	if (timer > 300) { m_changeScene->ChangeScene(Data::Scenes::SCENETYPE::TITLE); }

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
	NetworkClient::GetInstance().Recv(m_data, sizeof(m_data), &m_dataSize, this);
}

// ��M
int LoginScene::Reception(char * _data)
{
	_data;
	// �ڑ������Ƃ��̎��g�̃p�P�b�g���擾
	memcpy(&m_myPacket, _data, sizeof(Data::Pakets::LoginData));

	// ���O�C�����Ă�����
	if (m_myPacket.socket >= SOCKET_MIN&&m_myPacket.socket <= SOCKET_MAX)
	{
		//���g�̃\�P�b�g��o�^
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
/// �I��
/// </summary>
void LoginScene::End()
{
	if (m_effect->TextureListSize() != 0) { m_effect->LostTexture(); }
	if (m_uiManager != nullptr) { m_uiManager->End(); }
	delete m_uiManager;	m_uiManager = nullptr;
}

