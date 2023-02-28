#pragma once
#include "ItemBase.h"
#include"Player.h"

class Recovery : public ItemBase
{
private:
	int images; //画像
	bool Reset; //リセット
	int time;  //出現時間
public:
	Recovery();
	void Update();
	 void Draw()const;
	 void SetReset();
	 bool HitCheck(PlayerBullers* playerbullers);
	 
};

