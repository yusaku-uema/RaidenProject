#pragma once
#include"AdstractScene.h"

class CharaBase : public AdstractScene
{
private:
	int * bullets[10]; //�|�C���^�z��
	float speed; //�e�ۃX�s�[�h
	int image; //�e�ۉ摜
public:
	//CharaBase();
	//~CharaBase();
	//virtual AdstractScene* Update() = 0;
	//virtual void  Draw()const = 0;
	//virtual void Hit() = 0;
	//int GetBullets(); //�e��
};
