#include "CharaBase.h"

CharaBase::CharaBase()
{
	Speed = 1.5;
	Image = 0;
	
}

float  CharaBase::GetBullets_X(int i)const
{
	return bullets[i].x;
}

void CharaBase::SetBullets_X(int i, float j)
{
	bullets[i].x = j;
}

float CharaBase::GetBullets_Y(int i)const
{
	return bullets[i].y;
}

void CharaBase::SetBullets_Y(int i, float j)
{
	bullets[i].y = j;
}

bool CharaBase::GetBullets_flg(int i)const
{
	return bullets[i].Bulletslost;
}

void CharaBase::SetBullets_flg(int i, bool flg)
{
	bullets[i].Bulletslost = flg;
}
