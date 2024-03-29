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
	radius = 7;
	Reset = false;
}

void PlayerBullers::Update()
{
	if (Reset != true) //trueじゃなかったら
	{
		location.y -= 5;
		if (location.y > 480 || location.y < -10)
		{
			Reset = true;
		}
	}
}

void PlayerBullers::Draw()const
{
	if (Reset != true)DrawCircle(location.x, location.y, radius, GetColor(255, 0, 255), TRUE);//弾描画
}




void PlayerBullers::SetReset(bool a)
{
	Reset = a;
}
bool PlayerBullers::GetReset()
{
	return Reset;
}

Location PlayerBullers::GetBullets()
{
	return location;
}