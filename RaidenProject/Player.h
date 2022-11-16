#pragma once
#include"AdstractScene.h"

class Player : public AdstractScene
{
private:
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
	virtual AdstractScene* ChangeScene() override;
	virtual void Hit() {};
	void LifeCheck();
	int GetScore();
};
