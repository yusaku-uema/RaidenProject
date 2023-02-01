#pragma once
#include"BulletsBase.h"

class CharaBase : public BulletsBase
{
private:
	struct Bullets PlayerBullets[100]; 
	struct Bullets* bullets = PlayerBullets;
	float Speed;
	int Image;
public:
	CharaBase();
	virtual void Update() = 0;
	virtual void Draw() const = 0;
	virtual void Hit() = 0;
	float GetBullets_X(int i)const; //�e�ۍ��W�擾  //Draw() const �ŌĂяo���ɂ�Get�̕���const��
	void SetBullets_X(int i, float j); //�e�ۍ��W�ύX
	float GetBullets_Y(int i)const; //�e�ۍ��W�擾
	void SetBullets_Y(int i, float j); //�e�ۍ��W�ύX
	bool GetBullets_flg(int i)const; //�e�ۂ���ʊO�ɂ���̂�
	void SetBullets_flg(int i, bool); //�e�ۂ����݂��Ă���̂��̃t���O
};

