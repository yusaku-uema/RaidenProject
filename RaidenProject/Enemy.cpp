#include "Enemy.h"
#include"DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>

Enemy::Enemy()
{
	EnemyTime = 0;
	Bomber_Images = LoadGraph("images/Enemy/bomber.png");
	x = 0;
	y = 0;
	HP = 10;
	Point = 10;
	EnemyTyper = 0;
	Enemylost = true;
}

void Enemy::Update()
{
	//敵の位置を下にずらしていく
	y=  y+ 1;

	AliveEnemy(); //敵が生きているのかを判断する。

		CreateEnemy(); //敵を生成
}

void Enemy::Draw()const
{

	
		if (Enemylost == false)//敵が画面内、HPが残っていたら
		{
			DrawRotaGraph(x, y, 1.5f, 0, Bomber_Images, TRUE); //敵表示
		}

}

void Enemy::CreateEnemy() //敵を生成
{
	
		if (Enemylost == true)
		{
			Enemylost = false;
			EnemyTyper = GetRand(4);
			HP = 10;
			x = GetRand(610);
			y = GetRand(-210)-110; //-110から-210のランダム
		}
}

void Enemy::AliveEnemy() //敵が生きているのかを判断する。
{
	
		if (y > 500 || HP <= 0)//敵のｙ座標が500よりも大きくなったら、あるいはＨＰが0以下の場合
		{
			Enemylost = true; //敵を死亡判定に切り替え
		}
}


void Enemy::Hit()
{

}

bool Enemy::HitCheck(Player* player)
{
	return false;
}