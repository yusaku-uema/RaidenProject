#pragma once
#include"AdstractScene.h"

class Player : public AdstractScene
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
	virtual AdstractScene* ChangeScene() override;
	virtual void Hit() {};
	void LifeCheck();
	int GetScore();
};
