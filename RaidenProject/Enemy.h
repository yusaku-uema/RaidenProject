#pragma once
#include"AdstractScene.h"

class Enemy :public AdstractScene
{
private:
	int Enemy_image; //�G�摜
	float Enemy_X; //�GX���W
	float Enemy_Y; //�GY���W
	float Enemy_speed; //�G�̈ړ��X�s�[�h
	int Enemy_hp; //�G��HP
	int Enemy_point; //�G�̌��j�X�R�A

public:
	Enemy();
	virtual AdstractScene* Update()override;
	virtual void Draw() const override;
	//virtual void Hit();
	void HpCheck(); //HP�Ǘ�
	int GetPoint(); //�X�R�A�Q��


};
