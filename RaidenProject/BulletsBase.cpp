#include "BulletsBase.h"

BulletsBase::BulletsBase()
{
	Damage = 10;
	Speed = 3.5;
	for (int  i = 0; i < 100; i++)
	{
		PlayerBullets[i].x = 0;
		PlayerBullets[i].y = 0;
		PlayerBullets[i].Bulletslost = false;
		EnemyBullets[i].x = 0;
		EnemyBullets[i].y = 0;
		EnemyBullets[i].Bulletslost = false;
	}
}

int BulletsBase::GetDamage()
{
	return Damage;
}

float BulletsBase::GetBulletsSpeed()
{
	return Speed;
}