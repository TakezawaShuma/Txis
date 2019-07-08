#pragma once
#include <Keyboard.h>

#include "../../StepTimer.h"
#include "../NetworkPart/Data.h"
#include "../Effects/EffectManager.h"
#include "ISceneState.h"
#include "../../Callback.h"


class SceneState;

class GameScene :public ISceneChange
{
public:
	
public:

	GameScene(System::EffectManager* _effectManager);
	~GameScene();

	// �J�n����
	void Start();

	// �X�V
	bool Update();

	// ���s
	bool Execution(DX::StepTimer const& timer);

	// �`��
	void Draw();
	void DrawBegin();
	void DrawEnd();

	// �V�[���̐؂�ւ�
	void ChangeScene(Data::Scenes::SCENETYPE _nextScene);
	// �V�[���̃X�C�b�`
	ISceneState* SwitchingScene(Data::Scenes::SCENETYPE _nextScene);


private:

	// ���݃A�N�e�B�u�ȃV�[��
	ISceneState* m_activeScene;

	// �G�t�F�N�g��UI���Ǘ�����
	System::EffectManager* m_effectManager;


	// �^�C�}�[
	DX::StepTimer m_timer;
};
