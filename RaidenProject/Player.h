#pragma once
#include"CharaBase.h"

class player : public CharaBase
{
private:
	int Score; //�X�R�A
	int Life; //�c��c�@
	int Player_images[4]; //�v���C���[�C���[�W�摜
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
