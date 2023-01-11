#include "BulletsBase.h"

BulletsBase::BulletsBase()
{
	Damage = 10;
	Speed = 3.5;
}

int BulletsBase::GetDamage()
{
	return Damage;
}

float BulletsBase::GetBulletsSpeed()
{
	return Speed;
}