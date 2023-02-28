#include "EnemyBullers.h"
#include <math.h>
#include"DxLib.h"

EnemyBullers::EnemyBullers()
{
	location.x = 0;
	location.y = 0;
	radius = 5;
	Set = true;
	Time = 1; 
	Interval = 0;
	Reset = true;
	
}


void EnemyBullers::Update()
{
	if (Reset == false)
	{
		location.x += bullet_speed_x;
		location.y += bullet_speed_y;
	}
	if (location.x < 0 || location.x>640 || location.y > 480)
	{
		Reset = true;
		Set = true;

	}
}

void EnemyBullers::Draw()const
{
	if (Reset == false)
	{
		DrawCircle(location.x, location.y, radius, GetColor(255, 255, 10), TRUE);
	}
}

void EnemyBullers::SetBullers(float x, float y, float Enemy_x, float Enemy_y)
{

	if (Set == true)
	{
		Interval = GetRand(360) + 60;
		Set = false;
	}
	if (Time++ % Interval == 0)
	{
		if (Reset == true)
		{
			location.x = Enemy_x;
			location.y = Enemy_y;
			Reset = false;
			//プレイヤーにいる方向に射撃準備
			{
				float sb, sbx, sby, bx, by, sx, sy;

				sx = Enemy_x;
				sy = Enemy_y;

				bx = x;
				by = y;

				sbx = bx - sx;
				sby = by - sy;

				sb = sqrt(sbx * sbx + sby * sby);

				// １フレーム当たり2ドット移動するようにする
				bullet_speed_x = sbx / sb * 2;
				bullet_speed_y = sby / sb * 2;
			}
		}
	}

}

float EnemyBullers::GetBullets_Y()
{
	return location.y;
}

void EnemyBullers::SetReset(bool a)
{
	Reset = a;
}

bool EnemyBullers::GetReset()
{
	return Reset;
}

