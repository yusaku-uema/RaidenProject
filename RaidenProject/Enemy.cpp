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
	//“G‚ÌˆÊ’u‚ð‰º‚É‚¸‚ç‚µ‚Ä‚¢‚­
	y=  y+ 1;

	AliveEnemy(); //“G‚ª¶‚«‚Ä‚¢‚é‚Ì‚©‚ð”»’f‚·‚éB

		CreateEnemy(); //“G‚ð¶¬
}

void Enemy::Draw()const
{

	
		if (Enemylost == false)//“G‚ª‰æ–Ê“àAHP‚ªŽc‚Á‚Ä‚¢‚½‚ç
		{
			DrawRotaGraph(x, y, 1.5f, 0, Bomber_Images, TRUE); //“G•\Ž¦
		}

}

void Enemy::CreateEnemy() //“G‚ð¶¬
{
	
		if (Enemylost == true)
		{
			Enemylost = false;
			EnemyTyper = GetRand(4);
			HP = 10;
			x = GetRand(610);
			y = GetRand(-210)-110; //-110‚©‚ç-210‚Ìƒ‰ƒ“ƒ_ƒ€
		}
}

void Enemy::AliveEnemy() //“G‚ª¶‚«‚Ä‚¢‚é‚Ì‚©‚ð”»’f‚·‚éB
{
	
		if (y > 500 || HP <= 0)//“G‚Ì‚™À•W‚ª500‚æ‚è‚à‘å‚«‚­‚È‚Á‚½‚çA‚ ‚é‚¢‚Í‚g‚o‚ª0ˆÈ‰º‚Ìê‡
		{
			Enemylost = true; //“G‚ðŽ€–S”»’è‚ÉØ‚è‘Ö‚¦
		}
}


void Enemy::Hit()
{

}

bool Enemy::HitCheck(Player* player)
{
	return false;
}