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

	for (int i = 0; i < 100; i++)
	{
		Enemybullers[i] = new EnemyBullers();
	}



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
		location.y = GetRand(-100) - 50; //-110から-210のランダム
		Enemylost = false;
	}
}

void Enemy::AliveEnemy() //敵が生きているのかを判断する。
{

	if (location.y > 500 )//敵のｙ座標が500よりも大きくなったら
	{
		Enemylost = true; //敵を死亡判定に切り替え
	}
}

bool Enemy::HPCheck()
{
	bool ret = false;
	if (HP < 0)
	{
		Enemylost = true;
		ret = true;
		return ret;
	}
	return ret;
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

EnemyBullers* Enemy::GetBullet(int i) const
{
	return Enemybullers[i];
}



