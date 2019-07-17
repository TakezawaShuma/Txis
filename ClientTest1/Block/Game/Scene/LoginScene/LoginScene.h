#pragma once
// ���� -------------------------------
#include <Keyboard.h>
// ------------------------------------
// �`�� -------------------------------
#include "../../DrawManager.h"
// ------------------------------------
// �V�[�� -----------------------------
#include "../ISceneState.h"
// ------------------------------------
// �}�l�[�W���[ -----------------------
#include "../../InputManager.h"
#include "../../Effects/EffectManager.h"
// ------------------------------------
// UI ---------------------------------
#include "../../UI/UiMnager.h"
#include "../../UI/UI.h"
// ------------------------------------
// �R�[���o�b�N -----------------------
#include "../../Callback.h"
// ------------------------------------
// ���̑� -----------------------------
#include "../../NetworkPart/Data.h"
// ------------------------------------


class LoginScene :public ISceneState
{
public:
	LoginScene(ISceneChange* _changeScene);
	~LoginScene();

	// �J�n����
	void Start(System::EffectManager* _effect);

	// �X�V
	bool Update(DX::StepTimer const& _timer);

	// �`��
	void Draw();

	// ��M�������s��
	void Recv()override;

	// ��M
	int Reception(char* _data)override;

	// ���M����
	bool Send()override;

	// �V�[���̏I������
	void End();

private:

	int timer;

	// ���O�C�����Ɏ󂯎��p�P�b�g
	Data::Pakets::LoginData m_myPacket;

	// ���O�C���̐��۔���t���O
	bool m_loginFlag;

	// �G�t�F�N�g
	System::EffectManager* m_effect;

	// UI�Ǘ�
	UIManeger* m_uiManager;

};
