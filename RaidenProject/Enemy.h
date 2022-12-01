#pragma once
#include "CharaBase.h"

class Enemy :public CharaBase
{
private:
	int Bomber_Images; //�����@
	int Enemy_X; //�G���W
	int Enemy_Y; //�G���W
	int HP; //�c�@
	int Point; //�X�R�A

public:
	Enemy(); //�R���X�g���N�^
	void Update()override;
	void Draw()const override;
	void Hit()override;
	void HpCheck();
	void GetPoint();
};

