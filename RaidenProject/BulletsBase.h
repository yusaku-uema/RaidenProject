#pragma once
#include"SphereCollider.h"

class BulletsBase :public SphereCollider
{
protected:
	int Damage; //�^����_���[�W
	int Shooting_Time; //�e�̔��ˊԊu
	float Speed; //�e�̑��x

public:
	BulletsBase();
	virtual void Update() = 0;
	virtual void Draw()const = 0;
	int  GetDamage();
	float GetBulletsSpeed();
};

