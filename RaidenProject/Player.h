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
	int imagesnum; //画像番号
	float Player_X;
	float Player_Y;


public:
	Player();
	virtual void Update()override;
	virtual void Draw()const override; 
	virtual void Hit()override;
	void LifeCheck();
	int GetScore();
};
