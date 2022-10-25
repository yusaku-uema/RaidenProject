#pragma once
#include"CharaBase.h"

class player : public CharaBase
{
private:
	int score; //スコア
	int life; //残り残機
	int player_images; //プレイヤーイメージ画像
public:
	player();
	virtual AdstractScene* Update()override;
	virtual void Draw()const override; 
	//virtual void Hit()override;
	void LifeCheck();
	int GetScore();
};
