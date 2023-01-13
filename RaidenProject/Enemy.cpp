#include "Enemy.h"
#include"DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>

Enemy::Enemy()
{
	//Enemy_X = 310; //適当、のちに調整
	//Enemy_Y = 120; //適当、のちに調整
	//HP = 10; //適当、のちに調整
	//Point = 20; //適当、のちに調整
	LoadDivGraph("images/Enemy/Zerofighterplane (3).png", 7, 7, 1, 30, 30, Heri_Images);
	Bomber_Images = LoadGraph("images/Enemy/bomber.png");
	EnemyBoss_Images = LoadGraph("images/EnemyBosses/bos.png");
	Jetfighter_Images = LoadGraph("images/Enemy/plane_fighter_3.png");
	MesserschmittMe262 = LoadGraph("images/Enemy/me_262.png");
	Enemynum = 5;

	for (int  i = 0; i < Enemynum; i++)
	{
		EnemyNumber[i].Enemylost = false;
		EnemyNumber[i].EnemyTyper = GetRand(4);
		EnemyNumber[i].HP = 10;
		EnemyNumber[i].Point = 20;
		EnemyNumber[i].x = GetRand(610);
		EnemyNumber[i].y = -200;
	}

}

void Enemy::Update()
{
	for (int i = 0; i < Enemynum; i++)  //敵の位置を下にずらしていく
	{
		EnemyNumber[i].y = EnemyNumber[i].y + 1;
	}

	for (int i = 0; i < Enemynum; i++) //敵が画面外＆プレイヤーにやられたら初期化。
	{
		if (EnemyNumber[i].Enemylost == true)
		{
			EnemyNumber[i].Enemylost = false;
			EnemyNumber[i].EnemyTyper = GetRand(4);
			EnemyNumber[i].HP = 10;
			EnemyNumber[i].Point = 20;
			EnemyNumber[i].x = GetRand(610);
			EnemyNumber[i].y = -200; //検討中
		}
		
	}

}

void Enemy::Draw()const
{
	
	for (int i = 0; i < Enemynum; i++)
	{
		if (EnemyNumber[i].Enemylost == false)
		{
			DrawRotaGraph(EnemyNumber[i].x, EnemyNumber[i].y, 1.5f, 0, Bomber_Images, TRUE); //敵表示
		}
	}

	
	
}

void Enemy::Hit()
{

}