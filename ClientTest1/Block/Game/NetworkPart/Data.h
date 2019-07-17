

#pragma once
#ifndef DATA_DEFINED
#define DATA_DEFINED

#include <WinSock2.h>
#include <stdio.h>

#define BULLET_NUM 25
#define SOCKET_MIN 100
#define SOCKET_MAX 999

namespace Data
{
	namespace Scenes
	{
		enum SCENETYPE
		{
			//�ڑ���
			LOGIN,
			// �^�C�g���V�[��
			TITLE,
			// ���r�[�V�[��
			LOBBY,
			// �v���C�V�[��
			PLAY,
			// ���U���g�V�[��
			RESULT,
			// �߂�or�ؒf
			BACK,

			// �V�[���[��
			NON,
		};


		struct Scene
		{
			Scene() { nowScene = SCENETYPE::NON; nextScene = SCENETYPE::NON; }
			SCENETYPE nowScene;
			SCENETYPE nextScene;
		};

	}

	namespace Pakets
	{
		enum PaketID
		{
			PAKET_BASE = (int)0,
			LOGIN_PAKET = (int)100,
			LOBBY_PAKET = (int)200,
			PLAY_PAKET = (int)300,
			RESULT_PAKET = (int)400,

			SWITCH_PAKET = (int)500,
		};



		// ���
		struct IPaketData
		{
			// �p�P�b�g��ID
			PaketID paketId;
			// �V�[���Ǘ�
			Scenes::Scene scene;
			// �v���C���[ID
			SOCKET socket;
		};

		/// <summary>
		/// ���O�C���V�[���̃f�[�^
		/// </summary>
		/// �p�P�b�gID = 100
		struct LoginData : IPaketData
		{
			LoginData() { scene.nowScene = Scenes::SCENETYPE::LOGIN; scene.nextScene = Scenes::SCENETYPE::LOBBY; }
			LoginData(SOCKET _soc) { scene.nowScene = Scenes::SCENETYPE::LOGIN; scene.nextScene = Scenes::SCENETYPE::LOBBY; socket = _soc; }
		};

		/// <summary>
		/// ���r�[�ł���肷��f�[�^
		/// </summary>
		/// �p�P�b�gID = 200
		struct LobbyData :IPaketData
		{

			LobbyData() { scene.nowScene = Scenes::SCENETYPE::LOBBY; scene.nextScene = Scenes::SCENETYPE::NON; paketId = PaketID::LOBBY_PAKET; ready = false; }
			LobbyData(SOCKET _soc) { scene.nowScene = Scenes::SCENETYPE::LOBBY; scene.nextScene = Scenes::SCENETYPE::NON; paketId = PaketID::LOBBY_PAKET; socket = _soc; ready = false; }
			LobbyData(IPaketData _i) { scene.nowScene = _i.scene.nowScene; scene.nextScene = _i.scene.nextScene; paketId = _i.paketId; socket = _i.socket; ready = false; }

			// ��������
			bool ready;
		};

		/// <summary>
		/// �v���C�ł���肷��f�[�^
		/// </summary>
		/// �p�P�b�gID = 300
		struct PlayData :IPaketData
		{
			PlayData()
			{
				scene.nowScene = Scenes::SCENETYPE::PLAY;
				scene.nextScene = Scenes::SCENETYPE::NON;
				paketId = PaketID::PLAY_PAKET;
			}

			PlayData(SOCKET _soc)
			{
				scene.nowScene = Scenes::SCENETYPE::PLAY;
				scene.nextScene = Scenes::SCENETYPE::NON;
				paketId = PaketID::PLAY_PAKET;
				socket = _soc;
			}
			PlayData(IPaketData _i)
			{
				scene.nowScene = _i.scene.nowScene;
				scene.nextScene = _i.scene.nextScene;
				paketId = _i.paketId;
				socket = _i.socket;
			}
			void Start(DirectX::SimpleMath::Vector2 _vec)
			{
				hitPoint = 5;
				posX = _vec.x;
				posY = _vec.y;
				angle = 0;
			}
			// �̗�
			int hitPoint;
			// �ʒu
			float posX;
			float posY;

			// �����Ă���p�x
			float angle;

			// �e�̐����ʒu���L����
			float bulletPosX[BULLET_NUM];
			float bulletPosY[BULLET_NUM];
			bool bulletActive[BULLET_NUM];
		};


		/// <summary>
		/// ���U���g�ł���肷��f�[�^
		/// </summary>
		struct ResultData :IPaketData
		{
			ResultData() { scene.nowScene = Scenes::SCENETYPE::PLAY; scene.nextScene = Scenes::SCENETYPE::NON; paketId = PaketID::RESULT_PAKET; }
			ResultData(SOCKET _soc) { scene.nowScene = Scenes::SCENETYPE::PLAY; scene.nextScene = Scenes::SCENETYPE::NON; paketId = PaketID::RESULT_PAKET; socket = _soc; }
			ResultData(IPaketData _i) { scene.nowScene = _i.scene.nowScene; scene.nextScene = _i.scene.nextScene; paketId = PaketID::RESULT_PAKET; socket = _i.socket; }

			// ��荇����
			bool ready;

		};


		/// <summary>
		/// �؂�ւ���v�����͊������ɑ���(�󂯂�)�f�[�^
		/// </summary>
		/// �p�P�b�gID = 500
		struct SwitchingPakets :IPaketData
		{
			SwitchingPakets() { scene.nowScene = Scenes::SCENETYPE::NON; scene.nextScene = Scenes::SCENETYPE::NON; paketId = PaketID::SWITCH_PAKET; socket = (SOCKET)-1; }
			SwitchingPakets(Scenes::SCENETYPE _now, Scenes::SCENETYPE _next) { scene.nowScene = _now; scene.nextScene = _next; paketId = PaketID::SWITCH_PAKET; socket = (SOCKET)-1; }
			// �؂�ւ�(1=�؂�ւ�����/0=�؂�ւ��v��/-1=�؂�ւ����s)
			int switchFlag;
		};
	}

	// �l�b�g���[�N�̃G���[���
	std::string ErrorState(int errorNumber);
}
#endif // !DATA_DEFINED