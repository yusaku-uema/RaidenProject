#pragma once
#include"SphereCollider.h"

class BulletsBase :public SphereCollider
{
protected:
	int Damage; //—^‚¦‚éƒ_ƒ[ƒW
	int Shooting_Time; //’e‚Ì”­ËŠÔŠu
	float Speed; //’e‚Ì‘¬“x

public:
	BulletsBase();
	virtual void Update() = 0;
	virtual void Draw()const = 0;
	int  GetDamage();
	float GetBulletsSpeed();
};

