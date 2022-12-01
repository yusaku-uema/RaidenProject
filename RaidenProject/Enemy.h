#pragma once
#include "CharaBase.h"

class Enemy :public CharaBase
{
private:
	int Bomber_Images; //爆撃機
	int Enemy_X; //敵座標
	int Enemy_Y; //敵座標
	int HP; //残機
	int Point; //スコア

public:
	Enemy(); //コンストラクタ
	void Update()override;
	void Draw()const override;
	void Hit()override;
	void HpCheck();
	void GetPoint();
};

