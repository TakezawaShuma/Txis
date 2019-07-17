#pragma once
// ���� -------------------------------
#include <map>
// ------------------------------------
// �V�[�� -----------------------------
#include "../ISceneState.h"
// ------------------------------------
// �R�[���o�b�N -----------------------
#include "../../Callback.h"
// ------------------------------------
// ���̑� -----------------------------
#include "../../UI/UI.h"
#include "../../UI/UiMnager.h"
#include "../../NetworkPart/Data.h"
// ------------------------------------
class OtherPlayer;

class LobbyScene:public ISceneState
{
private:

	static const int FRAME_SIZE_X = 600;
	static const int FRAME_SIZE_Y = 64;
	static const int NUMBER_SIZE_X = 32;
	static const int NUMBER_SIZE_Y = 64;


public:
	LobbyScene(ISceneChange* _change);
	~LobbyScene();

	// �J�n����
	void Start(System::EffectManager* _effect);

	// �X�V
	bool Update(DX::StepTimer const& _timer);

	// �`��
	void Draw();

	//�V�[���̏I������
	void End();

	// ��M����
	void Recv();

	// ��M�����f�[�^����������
	int Reception(char* _data)override;

	// ���M����
	bool Send()override;

private:
	// �������g
	Data::Pakets::LobbyData m_player;
	// ���̃v���C���[���X�g
	std::map<SOCKET, Data::Pakets::LobbyData> m_otherList;

	// ���M�f�[�^���X�g
	std::list<Data::Pakets::LobbyData> m_sendData;

	// �폜�v���C���[���X�g
	std::vector<OtherPlayer> m_delOtherList;


	// Title ���� Play �ɐ؂�ւ�邽�߂̎���
	int timeCount;

	// �t���[���摜
	System::DrawData* m_frame1;
	System::DrawData* m_frame2;

	// �����摜
	System::DrawData* m_number;
	// OK�摜
	System::DrawData* m_ok;

private:
	// ���M�f�[�^�̕ϊ�
	void ConversionSendDatas(Data::Pakets::LobbyData* _playerData);

};