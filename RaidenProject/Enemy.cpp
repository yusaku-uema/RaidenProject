#include "Enemy.h"
#include"DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>

Enemy::Enemy()
{
	//Enemy_X = 310; //“K“–A‚Ì‚¿‚É’²®
	//Enemy_Y = 120; //“K“–A‚Ì‚¿‚É’²®
	//HP = 10; //“K“–A‚Ì‚¿‚É’²®
	//Point = 20; //“K“–A‚Ì‚¿‚É’²®
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


	for (int i = 1; i < Enemynum; i++) //“G‚ªd‚È‚Á‚Ä•\¦‚³‚ê‚Ä‚¢‚È‚¢‚©
	{
		if (EnemyNumber[i - 1].Enemylost == false) {
			if (CreateHit(EnemyNumber[i].x, EnemyNumber[i].y, EnemyNumber[i].x + 24, EnemyNumber[i].y + 18, EnemyNumber[i - 1].x, EnemyNumber[i - 1].y, EnemyNumber[i - 1].x + 24, EnemyNumber[i - 1].y + 18) == true)
			{
				EnemyNumber[i].Enemylost = true;
			}
		}
	}

	


}

void Enemy::Update()
{
	for (int i = 0; i < Enemynum; i++)  //“G‚ÌˆÊ’u‚ğ‰º‚É‚¸‚ç‚µ‚Ä‚¢‚­
	{
		EnemyNumber[i].y = EnemyNumber[i].y + 1;
	}

	AliveEnemy(); //“G‚ª¶‚«‚Ä‚¢‚é‚Ì‚©‚ğ”»’f‚·‚éB
	//CreateEnemy(); //“G‚ğ¶¬
}

void Enemy::Draw()const
{
	
	for (int i = 0; i < Enemynum; i++)
	{
		if (EnemyNumber[i].Enemylost == false)//“G‚ª‰æ–Ê“àAHP‚ªc‚Á‚Ä‚¢‚½‚ç
		{
			switch (EnemyNumber[i].EnemyTyper) //•\¦‚·‚é“G‚Ì‰æ‘œ‚ğswitch•¶‚Å‘I‘ğ
			{
			case 1:
				DrawRotaGraph(EnemyNumber[i].x, EnemyNumber[i].y, 1.5f, 0, Bomber_Images, TRUE); //“GA”šŒ‚‹@•\¦
				break;
			}
			DrawRotaGraph(EnemyNumber[i].x, EnemyNumber[i].y, 1.5f, 0, Bomber_Images, TRUE); //“G•\¦
		}
	}

}

void Enemy::CreateEnemy() //“G‚ğ¶¬
{
	for (int i = 0; i < Enemynum; i++) //“G‚ª‰æ–ÊŠO•HP=0‚È‚ç‰Šú‰»B
	{
		if (EnemyNumber[i].Enemylost == true)
		{
			EnemyNumber[i].Enemylost = false;
			EnemyNumber[i].EnemyTyper = GetRand(4);
			EnemyNumber[i].HP = 10;
			EnemyNumber[i].x = GetRand(610);
			EnemyNumber[i].y = -200; //ŒŸ“¢’†
			EnemyNumber[i].CollisionX = EnemyNumber[i].x + 24;
		}

	}

}

void Enemy::AliveEnemy() //“G‚ª¶‚«‚Ä‚¢‚é‚Ì‚©‚ğ”»’f‚·‚éB
{
	for (int  i = 0; i < Enemynum; i++)
	{
		if (EnemyNumber[i].y > 500|| EnemyNumber[i].HP<=0)//“G‚Ì‚™À•W‚ª500‚æ‚è‚à‘å‚«‚­‚È‚Á‚½‚çA‚ ‚é‚¢‚Í‚g‚o‚ª0ˆÈ‰º‚Ìê‡
		{
			EnemyNumber[i].Enemylost = true; //“G‚ğ€–S”»’è‚ÉØ‚è‘Ö‚¦
		}
	}
}

float Enemy::CreateHit(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2) //“G¶¬‚ÉA“G“¯m‚ªd‚È‚ç‚È‚¢‚æ‚¤‚É
{
	//DrawRotaGraphŠÖ” ‚Íw’è‚µ‚½À•W‚ª’†‰›
	int L1 = x1 - w1; // À•W‚Æ‰æ‘œ‚Ì‘å‚«‚³¶‘¤‚Ì”»’è
	int R1 = x1 + w1; // À•W‚Æ‰æ‘œ‚Ì‘å‚«‚³‰E‘¤‚Ì”»’è
	int L2 = x2 - w2; // À•W‚Æ‰æ‘œ‚Ì‘å‚«‚³¶‘¤‚Ì”»’è
	int R2 = x2 + w2; // À•W‚Æ‰æ‘œ‚Ì‘å‚«‚³‰E‘¤‚Ì”»’è

	int U1 = y1 - h1;  // ã
	int D1 = y1 + h1; // ‰º(ã+c•)
	int U2 = y2 - h2; // ã
	int D2 = y2 + h2; // ‰º(ã+c•)

	if (R1 < L2 && R2 < L1 && D1 < U2 && D2 < U1)
	{
		//“–‚½‚ç‚È‚©‚Á‚½.
		return false;
	}
	else {
		return true;
	}

	
}

void Enemy::Hit()
{
	
}