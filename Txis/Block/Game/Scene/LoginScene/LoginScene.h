#pragma once
// 既存 -------------------------------
#include <Keyboard.h>
// ------------------------------------
// 描画 -------------------------------
#include "../../DrawManager.h"
// ------------------------------------
// シーン -----------------------------
#include "../ISceneState.h"
// ------------------------------------
// マネージャー -----------------------
#include "../../InputManager.h"
#include "../../Effects/EffectManager.h"
// ------------------------------------
// UI ---------------------------------
#include "../../UI/UiMnager.h"
#include "../../UI/UI.h"
// ------------------------------------
// コールバック -----------------------
#include "../../Callback.h"
// ------------------------------------
// その他 -----------------------------
#include "../../NetworkPart/Data.h"
// ------------------------------------


class LoginScene :public ISceneState
{
public:
	LoginScene(ISceneChange* _changeScene);
	~LoginScene();

	// 開始処理
	void Start(System::EffectManager* _effect);

	// 更新
	bool Update(DX::StepTimer const& _timer);

	// 描画
	void Draw();

	// 受信処理を行う
	void Recv()override;

	// 受信
	int Reception(char* _data)override;


	// シーンの終了処理
	void End();

private:

	int timer;

	Data::Pakets::LoginData m_myPacket;

	// エフェクト
	System::EffectManager* m_effect;

	// UI管理
	UIManeger* m_uiManager;

	// 送信データ
	char m_data[1024];

};
