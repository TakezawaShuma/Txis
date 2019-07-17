#pragma once
// 既存 ---------------------
#include <Keyboard.h>
// --------------------------
// シーン -------------------
#include "../ISceneState.h"
// --------------------------
// 描画関係 -----------------
#include "../../DrawManager.h"
// --------------------------
// 通信関係 -----------------
#include "../../NetworkPart/NetworkManeger.h"
// --------------------------
// その他 -------------------
#include "../../StepTimer.h"
// --------------------------

class Player;

class ResultScene : public ISceneState
{
public:
	ResultScene(ISceneChange* _change);
	~ResultScene();


	// 開始処理
	void Start(System::EffectManager* _effect);

	// 更新
	bool Update(DX::StepTimer const& _timer);

	// 描画
	void Draw();

	//シーンの終了処理
	void End();

	void Recv()override;

	int Reception(char* _data)override;

	// 送信処理
	bool Send()override;
private:
	// シェーダー
	System::EffectManager* m_effect;
	
	// 貰うデータサイズ
	//PlayerData m_myData;

	// 送るデータサイズ
	//PlayerData m_sendData;

	// ランクの画像
	System::DrawData* m_ranks;
};
