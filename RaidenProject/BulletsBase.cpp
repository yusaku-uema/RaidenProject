#include "BulletsBase.h"

BulletsBase::BulletsBase()
{
	Damage = 10;
	Speed = 3.5;
	Shooting_Time = 1;
}

int BulletsBase::GetDamage()
{
	return Damage;
}

float BulletsBase::GetBulletsSpeed()
{
	return Speed;
}
