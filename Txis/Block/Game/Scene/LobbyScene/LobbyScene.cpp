#include "../../pch.h"
// �}�l�[�W���[�֌W -------------------
#include "../../InputManager.h"
#include "../../NetworkPart/NetworkManeger.h"
#include "../../DrawManager.h"
// ------------------------------------
// �l�b�g���[�N�֌W -------------------
#include "../../NetworkPart/NetworkClient.h" 
// ------------------------------------
// �V�[���֌W -------------------------
#include "LobbyScene.h"
#include "../TitleScene/TitleScene.h"
#include "../PlayScene/PlayScene.h"
// ------------------------------------
// �Q�[�����̂��̊֌W -----------------
#include "../PlayScene/Player.h"
#include "../PlayScene/OtherPlayer.h"
// ------------------------------------




LobbyScene::LobbyScene(ISceneChange* _change): m_frame1(nullptr),m_frame2(nullptr),m_number(nullptr),m_ok(nullptr)
{
	m_changeScene = _change;
}

LobbyScene::~LobbyScene()
{
	End();
}

/// <summary>
/// ����������
/// </summary>
/// <param name="_effect"></param>
void LobbyScene::Start(System::EffectManager* _effect)
{
	_effect;
	m_player.ready = false;

	m_sendData.socket = NetworkClient::GetInstance().GetMySocket();
	m_sendData.scene.nowScene = Data::Scenes::SCENETYPE::LOBBY;
	m_sendData.scene.nextScene = Data::Scenes::SCENETYPE::NON;
	m_sendData.ready = false;
	timeCount = 180;

	// �����p�̃t���[�����쐬
	m_frame1 = new System::DrawData();
	System::DrawManager::GetInstance().LoadTexture(*m_frame1, L"Resources/LobbyLounge/Frame.png");
	m_frame1->SetRect(FRAME_SIZE_X, FRAME_SIZE_Y);
	m_frame1->SetPos(100, 8);

	// ���v���C���[�p�̃t���[�����쐬
	m_frame2 = new System::DrawData();
	System::DrawManager::GetInstance().LoadTexture(*m_frame2, L"Resources/LobbyLounge/Frame2.png");
	m_frame2->SetRect(FRAME_SIZE_X, FRAME_SIZE_Y);
	
	// �����p�摜���쐬
	m_number = new System::DrawData();
	System::DrawManager::GetInstance().LoadTexture(*m_number, L"Resources/LobbyLounge/Number.png");

	// ���������摜���쐬
	m_ok = new System::DrawData();
	System::DrawManager::GetInstance().LoadTexture(*m_ok, L"Resources/LobbyLounge/OK.png");
	m_ok->SetRect(64, 64);


	memcpy(m_data, &m_sendData, sizeof(m_data));
	NetworkClient::GetInstance().Send(m_data, sizeof(m_data));
}

/// <summary>
/// �X�V����
/// </summary>
/// <param name="_timer"></param>
/// <returns></returns>
bool LobbyScene::Update(DX::StepTimer const& _timer)
{

	float time = (float)_timer.GetTotalSeconds();
	time;
	Data::Pakets::LobbyData buf;
	int i = 0;
	// ��M(�ق�Ƃ͑��X���b�h�𗧂ĂĂ�鎖)
	NetworkClient::GetInstance().Recv(m_data,sizeof(m_data),&i,this);



	// OK����
	// Enter �������Ə�����������
	if (System::InputManager::GetInstance().GetKeyTracker().IsKeyPressed(DirectX::Keyboard::Enter))
	{
		m_sendData.ready = true;
		memcpy(m_data, &m_sendData, sizeof(m_data));
		NetworkClient::GetInstance().Send(m_data, sizeof(m_data));
	}
	// T �������ƃ^�C�g����
	else if (System::InputManager::GetInstance().GetKeyTracker().IsKeyPressed(DirectX::Keyboard::T))
	{
		m_sendData.ready = false;
		m_sendData.scene.nextScene = Data::Scenes::SCENETYPE::TITLE;
		memcpy(m_data, &m_sendData, sizeof(m_data));
		NetworkClient::GetInstance().Send(m_data, sizeof(m_data));
		m_changeScene->ChangeScene(Data::Scenes::SCENETYPE::TITLE);
		return true;
	}


	// �V�[���؂�ւ�
	// -------------------------------------------------------------------------------------------------------------------------------------------------
	if (m_player.socket == NetworkClient::GetInstance().GetMySocket())
	{
		if (m_player.scene.nextScene == Data::Scenes::SCENETYPE::PLAY)
		{
			if (timeCount <= 0)
			{
				for (std::map<SOCKET,Data::Pakets::LobbyData>::iterator ite = m_otherList.begin(); ite != m_otherList.end(); ite++)
				{
					NetworkClient::GetInstance().SetOthrts(ite->first);
				}
				m_changeScene->ChangeScene(Data::Scenes::SCENETYPE::PLAY);
				return true;
			}
			timeCount--;
		}
	}
	return true;
}

/// <summary>
/// �`�揈��
/// </summary>
void LobbyScene::Draw()
{
	// ���g�̕\��
	if (m_player.socket != 0)
	{
		if (m_frame1 != nullptr) System::DrawManager::GetInstance().Draw(*m_frame1);
		if (m_player.ready)
		{
			m_ok->SetPos(500, m_frame1->GetPos().y);
			if (m_ok != nullptr) System::DrawManager::GetInstance().Draw(*m_ok);
		}
	}

	// ���̃v���C���[��������\��
	int i = 0;
	for (std::map<SOCKET, Data::Pakets::LobbyData>::iterator ite = m_otherList.begin(); ite != m_otherList.end(); ite++,i++)
	{
		int n = ite->first;
		LONG num[3];
		num[0]= n / 100;
		n = n % 100;
		num[1] = n / 10;
		num[2] = n % 10;

		if (m_frame2 != nullptr)
		{
			m_frame2->SetPos(m_frame1->GetPos().x, (m_frame1->GetPos().y + 80) + (80 * i));
			System::DrawManager::GetInstance().Draw(*m_frame2);

			for (int j = 0; j < 3; j++)
			{
				LONG h = num[j] / 5;
				LONG w = num[j] % 5;
				if (m_number != nullptr)
				{
					m_number->SetRect(NUMBER_SIZE_X * w, NUMBER_SIZE_Y * h, NUMBER_SIZE_X * (w + 1), NUMBER_SIZE_Y * (h + 1));
					m_number->SetPos((m_frame2->GetPos().x + NUMBER_SIZE_Y) + (NUMBER_SIZE_X * j), m_frame2->GetPos().y);

					System::DrawManager::GetInstance().Draw(*m_number);
				}
			}
			if (ite->second.ready == 1)
			{
				m_ok->SetPos(500, m_frame2->GetPos().y);
				if (m_ok != nullptr) System::DrawManager::GetInstance().Draw(*m_ok);
			}

		}
	}
}


/// <summary>
/// �I������
/// </summary>
void LobbyScene::End()
{
	//m_otherList.clear();
	m_delOtherList.clear();

	delete m_frame1;	m_frame1 = nullptr;
	delete m_frame2;	m_frame2 = nullptr;
	delete m_number;	m_number = nullptr;
	delete m_ok;		m_ok = nullptr;
}

/// <summary>
/// ��M�����Ƃ��̏���
/// </summary>
/// <param name="_data"></param>
/// <returns></returns>
int LobbyScene::Reception(char * _data)
{
	_data;
	Data::Pakets::LobbyData p;
	memcpy(&p, _data, sizeof(Data::Pakets::LobbyData));

	if (p.socket == NetworkClient::GetInstance().GetMySocket()) 
	{
		m_player = p; 
	}
	else
	{
		if (p.socket >= SOCKET_MIN&&p.socket <= SOCKET_MAX) {
			std::map<SOCKET, Data::Pakets::LobbyData>::iterator itr = m_otherList.find(p.socket);

			if (itr == m_otherList.end()) { m_otherList.insert(std::make_pair(p.socket, p)); }
			else { itr->second = p; }

			// ���O�A�E�g����
			if (p.scene.nextScene == Data::Scenes::SCENETYPE::BACK)
			{
				m_otherList.erase(p.socket);
			}
		}
	}

	return 0;
}


void LobbyScene::ConversionSendDatas(Data::Pakets::LobbyData* _playerData)
{
	_playerData->scene.nowScene = Data::Scenes::SCENETYPE::PLAY;
}

