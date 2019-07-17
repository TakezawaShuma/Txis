#pragma once
// ���� ---------------------
#include <Keyboard.h>
// --------------------------
// �V�[�� -------------------
#include "../ISceneState.h"
// --------------------------
// �`��֌W -----------------
#include "../../DrawManager.h"
// --------------------------
// �ʐM�֌W -----------------
#include "../../NetworkPart/NetworkManeger.h"
// --------------------------
// ���̑� -------------------
#include "../../StepTimer.h"
// --------------------------

class Player;

class ResultScene : public ISceneState
{
public:
	ResultScene(ISceneChange* _change);
	~ResultScene();


	// �J�n����
	void Start(System::EffectManager* _effect);

	// �X�V
	bool Update(DX::StepTimer const& _timer);

	// �`��
	void Draw();

	//�V�[���̏I������
	void End();

	void Recv()override;

	int Reception(char* _data)override;

	// ���M����
	bool Send()override;
private:
	// �V�F�[�_�[
	System::EffectManager* m_effect;
	
	// �Ⴄ�f�[�^�T�C�Y
	//PlayerData m_myData;

	// ����f�[�^�T�C�Y
	//PlayerData m_sendData;

	// �����N�̉摜
	System::DrawData* m_ranks;
};
