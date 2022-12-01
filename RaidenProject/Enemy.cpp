#include "Enemy.h"
#include"DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>

Enemy::Enemy()
{
	Enemy_X = 310; //適当、のちに調整
	Enemy_Y = 120; //適当、のちに調整
	HP = 10; //適当、のちに調整
	Point = 20; //適当、のちに調整
	Bomber_Images = LoadGraph("images/Enemy/bomber.png");
}

void Enemy::Update()
{
	//敵処理を書く、今は動かない
}

void Enemy::Draw()const
{
	DrawRotaGraph(Enemy_X, Enemy_Y, 1.5f, 0, Bomber_Images, TRUE); //敵表示
}

void Enemy::Hit()
{

}