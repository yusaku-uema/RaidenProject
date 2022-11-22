#pragma once
#include"CharaBase.h"

class Player : public CharaBase
{
private:
	int Score; //�X�R�A
	int Life; //�c��c�@
	int Player_images[4]; //�v���C���[�C���[�W�摜
	int imagesnum; //�摜�ԍ�
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
