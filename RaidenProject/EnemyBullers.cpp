#include "EnemyBullers.h"
#include <math.h>
#include"DxLib.h"

EnemyBullers::EnemyBullers()
{
	location.x = 0;
	location.y = 0;
	radius = 5;
}


void EnemyBullers::Update()
{
	if (Reset == false)
	{
		location.x += bullet_speed_x;
		location.y += bullet_speed_y;
	}

	if (location.x < 0 || location.x>640 || location.y < 0 || location.y>480)
	{
		Reset = true;
	}

}

void EnemyBullers::Draw()const
{
	DrawCircle(location.x, location.y, radius, GetColor(255, 255, 10), TRUE);
}

//void EnemyBullers::SetBullers(float x, float y)
//{
//	if (Reset == true)
//	{
//		Reset = false;
//		//プレイヤーにいる方向に射撃準備
//		{
//			float sb, sbx, sby, bx, by, sx, sy;
//
//			sx = location.x;
//			sy = location.y;
//
//			bx = x;
//			by = y;
//
//			sbx = bx - sx;
//			sby = by - sy;
//
//			sb = sqrt(sbx * sbx + sby * sby);
//
//			// １フレーム当たり2ドット移動するようにする
//			bullet_speed_x = sbx / sb * 2;
//			bullet_speed_y = sby / sb * 2;
//		}
//	}
//}

float EnemyBullers::GetBullets_Y()
{
	return location.y;
}