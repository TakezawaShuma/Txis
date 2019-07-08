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

	// 開始処理
	void Start();

	// 更新
	bool Update();

	// 実行
	bool Execution(DX::StepTimer const& timer);

	// 描画
	void Draw();
	void DrawBegin();
	void DrawEnd();

	// シーンの切り替え
	void ChangeScene(Data::Scenes::SCENETYPE _nextScene);
	// シーンのスイッチ
	ISceneState* SwitchingScene(Data::Scenes::SCENETYPE _nextScene);


private:

	// 現在アクティブなシーン
	ISceneState* m_activeScene;

	// エフェクトやUIを管理する
	System::EffectManager* m_effectManager;


	// タイマー
	DX::StepTimer m_timer;
};
