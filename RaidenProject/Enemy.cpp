#include "Enemy.h"
#include"DxLib.h"
#define _USE_MATH_DEFINES
#include"SphereCollider.h"
#include <math.h>

Enemy::Enemy()
{
	EnemyTime = 0;
	Bomber_Images = LoadGraph("images/Enemy/bomber.png");
	location.x = 0;
	location.y = 0;
	HP = 10;
	Point = 10;
	EnemyTyper = 0;
	Enemylost = true;
	radius = 10;
	Interval = 0;
	Bullers_num = 1;

}

void Enemy::Update()
{
	//敵の位置を下にずらしていく
	location.y += 1;

	AliveEnemy(); //敵が生きているのかを判断する。

	CreateEnemy(); //敵を生成
}

void Enemy::Draw()const
{

	DrawRotaGraph(location.x, location.y, 1.5f, 0, Bomber_Images, TRUE); //敵表示

}

void Enemy::CreateEnemy() //敵を生成
{

	if (Enemylost == true)
	{
		EnemyTyper = GetRand(4);
		HP = 20;
		location.x = GetRand(570) + 50;
		location.y = GetRand(-210) - 110; //-110から-210のランダム
	}
}

void Enemy::AliveEnemy() //敵が生きているのかを判断する。
{

	if (location.y > 500 || HP <= 0)//敵のｙ座標が500よりも大きくなったら、あるいはＨＰが0以下の場合
	{
		Enemylost = true; //敵を死亡判定に切り替え
	}
}


void Enemy::Hit(int a)
{
	HP -= a;
}


bool Enemy::HitCheck(PlayerBullers* playerbullers)
{
	bool ret = false; //戻り値

	if (HitSphere(playerbullers) == true)
	{
		ret = true;
	}

	return ret;
}

float Enemy::Enemy_Y()
{
	return location.y;
}

int Enemy::Getnum()
{
	return Bullers_num;
}

