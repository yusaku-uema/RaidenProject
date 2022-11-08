#pragma once
#include"AdstractScene.h"

class Enemy :public AdstractScene
{
private:
	int Enemy_image; //敵画像
	float Enemy_X; //敵X座標
	float Enemy_Y; //敵Y座標
	float Enemy_speed; //敵の移動スピード
	int Enemy_hp; //敵のHP
	int Enemy_point; //敵の撃破スコア

public:
	Enemy();
	virtual AdstractScene* Update()override;
	virtual void Draw() const override;
	//virtual void Hit();
	void HpCheck(); //HP管理
	int GetPoint(); //スコア参照


};
