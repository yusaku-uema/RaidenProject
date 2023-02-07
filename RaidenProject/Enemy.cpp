#include "Enemy.h"
#include"DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>

Enemy::Enemy()
{
	EnemyTime = 0;
	Bomber_Images = LoadGraph("images/Enemy/bomber.png");
	EnemyBoss_Images = LoadGraph("images/EnemyBosses/bos.png");
	Enemynum = 0;

	//for (int i = 1; i < Enemynum; i++) //敵が重なって表示されていないか
	//{
	//	if (EnemyNumber[i - 1].Enemylost == false) {
	//		if (CreateHit(EnemyNumber[i].x, EnemyNumber[i].y, EnemyNumber[i].x + 24, EnemyNumber[i].y + 18, EnemyNumber[i - 1].x, EnemyNumber[i - 1].y, EnemyNumber[i - 1].x + 24, EnemyNumber[i - 1].y + 18) == true)
	//		{
	//			EnemyNumber[i].Enemylost = true;
	//		}
	//	}
	//}

	


}

void Enemy::Update()
{
	for (int i = 0; i < Enemynum; i++)  //敵の位置を下にずらしていく
	{
		EnemyNumber[i].y = EnemyNumber[i].y + 1;
	}

	AliveEnemy(); //敵が生きているのかを判断する。

	if (EnemyTime++ % 120 == 0) {
		if (Enemynum < EnemyMax) { 
			Enemynum++; }
		CreateEnemy(); //敵を生成
	}
}

void Enemy::Draw()const
{
	
	for (int i = 0; i < Enemynum; i++)
	{
		if (EnemyNumber[i].Enemylost == false)//敵が画面内、HPが残っていたら
		{
			DrawRotaGraph(EnemyNumber[i].x, EnemyNumber[i].y, 1.5f, 0, Bomber_Images, TRUE); //敵表示
		}
	}

}

void Enemy::CreateEnemy() //敵を生成
{
	for (int i = 0; i < Enemynum; i++) //敵が画面外＆HP=0なら初期化。
	{
		if (EnemyNumber[i].Enemylost == true)
		{
			EnemyNumber[i].Enemylost = false;
			EnemyNumber[i].EnemyTyper = GetRand(4);
			EnemyNumber[i].HP = 10;
			EnemyNumber[i].x = GetRand(610);
			EnemyNumber[i].y = -200; //検討中
			EnemyNumber[i].CollisionX = EnemyNumber[i].x + 24;
		}

	}

}

void Enemy::AliveEnemy() //敵が生きているのかを判断する。
{
	for (int  i = 0; i < EnemyMax; i++)
	{
		if (EnemyNumber[i].y > 500|| EnemyNumber[i].HP<=0)//敵のｙ座標が500よりも大きくなったら、あるいはＨＰが0以下の場合
		{
			EnemyNumber[i].Enemylost = true; //敵を死亡判定に切り替え
		}
	}
}

//float Enemy::CreateHit(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2) //敵生成時に、敵同士が重ならないように
//{
//	//DrawRotaGraph関数 は指定した座標が中央
//	int L1 = x1 - w1; // 座標と画像の大きさ左側の判定
//	int R1 = x1 + w1; // 座標と画像の大きさ右側の判定
//	int L2 = x2 - w2; // 座標と画像の大きさ左側の判定
//	int R2 = x2 + w2; // 座標と画像の大きさ右側の判定
//
//	int U1 = y1 - h1;  // 上
//	int D1 = y1 + h1; // 下(上+縦幅)
//	int U2 = y2 - h2; // 上
//	int D2 = y2 + h2; // 下(上+縦幅)
//
//	if (R1 < L2 && R2 < L1 && D1 < U2 && D2 < U1)
//	{
//		//当たらなかった.
//		return false;
//	}
//	else {
//		return true;
//	}
//
//	
//}

void Enemy::Hit()
{
	
}