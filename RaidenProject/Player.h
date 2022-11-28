#pragma once
#include"CharaBase.h"

class Player : public CharaBase
{
private:

	//Key
	int g_KeyFlg; 
	int g_OldKey; //古いkey
	int g_NowKey; //現在のKey

	//自機
	int Score; //スコア
	int Life; //残り残機
	int Player_images[4]; //プレイヤーイメージ画像
	int imagesnum; //プレイヤー画像番号
	float Player_X; //プレイヤーX座標
	float Player_Y; //プレイヤーY座標


public:
	Player(); //コンストラクタ
	virtual void Update()override; //描画処理以外
	virtual void Draw()const override; //描画
	virtual void Hit()override;
	void LifeCheck();
	int GetScore();
};
