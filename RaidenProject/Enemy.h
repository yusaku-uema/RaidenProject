#pragma once
#include"AdstractScene.h"

class Enemy :public AdstractScene
{
private:
	int Enemy_image; //Gæ
	float Enemy_X; //GXÀW
	float Enemy_Y; //GYÀW
	float Enemy_speed; //GÌÚ®Xs[h
	int Enemy_hp; //GÌHP
	int Enemy_point; //GÌjXRA

public:
	Enemy();
	virtual AdstractScene* Update()override;
	virtual void Draw() const override;
	//virtual void Hit();
	void HpCheck(); //HPÇ
	int GetPoint(); //XRAQÆ


};
