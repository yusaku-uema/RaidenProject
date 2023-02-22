#pragma once
#include"SphereCollider.h"

class BulletsBase :public SphereCollider
{
protected:
	int Damage; //�^����_���[�W
	int Shooting_Time; //�e�̔��ˊԊu
	float Speed; //�e�̑��x
	bool Reset; //���Z�b�g�t���O�i�e�ۂ�ł��o�������ݒ�)

public:
	BulletsBase();
	virtual void Update() = 0;
	virtual void Draw()const = 0;
	int  GetDamage();
	float GetBulletsSpeed();
	
	void SetReset(bool a)
	{
		Reset = a;
	}
		bool GetReset()
	{
		return Reset;
	}
};

