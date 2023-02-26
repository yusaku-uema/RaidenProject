#include "PlayerBullers.h"
#include"DxLib.h"

PlayerBullers::PlayerBullers()
{
	location.x = 0;
	location.y = 0;
	Reset = true;
}

void PlayerBullers::SetBullers(float x, float y)
{
	location.x = x;
	location.y = y;
	radius = 5;
	Reset = false;
}

void PlayerBullers::Update()
{
	if (Reset != true) //true‚¶‚á‚È‚©‚Á‚½‚ç
	{
		location.y--;
	}

	if (location.y > 480 || location.y < -10)
	{
		Reset = true;
	}

}

void PlayerBullers::Draw()const
{
	if (Reset!=true)DrawCircle(location.x,location.y, radius, GetColor(255, 0, 255), TRUE);//’e•`‰æ
}


void PlayerBullers::SetReset(bool a)
{
	Reset = a;
}
bool PlayerBullers::GetReset()
{
	return Reset;
}