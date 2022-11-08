#pragma once
#include"CharaBase.h"

class player : public CharaBase
{
private:
	int Score; //スコア
	int Life; //残り残機
	int Player_images[4]; //プレイヤーイメージ画像
	int imagesnum; //画像番号
	float Player_X;
	float Player_Y;
public:
	player();
	virtual AdstractScene* Update()override;
	virtual void Draw()const override; 
	virtual void Hit() {};
	void LifeCheck();
	int GetScore();
};
