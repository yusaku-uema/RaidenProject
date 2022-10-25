#pragma once
#include"AdstractScene.h"

class CharaBase : public AdstractScene
{
private:
	int * bullets[10]; //ポインタ配列
	float speed; //弾丸スピード
	int image; //弾丸画像
public:
	//CharaBase();
	//~CharaBase();
	//virtual AdstractScene* Update() = 0;
	//virtual void  Draw()const = 0;
	//virtual void Hit() = 0;
	//int GetBullets(); //弾丸
};
