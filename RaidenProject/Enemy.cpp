#include "Enemy.h"
#include"DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>

Enemy::Enemy()
{
	//Enemy_X = 310; //�K���A�̂��ɒ���
	//Enemy_Y = 120; //�K���A�̂��ɒ���
	//HP = 10; //�K���A�̂��ɒ���
	//Point = 20; //�K���A�̂��ɒ���
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


	for (int i = 1; i < Enemynum; i++) //�G���d�Ȃ��ĕ\������Ă��Ȃ���
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
	for (int i = 0; i < Enemynum; i++)  //�G�̈ʒu�����ɂ��炵�Ă���
	{
		EnemyNumber[i].y = EnemyNumber[i].y + 1;
	}

	AliveEnemy(); //�G�������Ă���̂��𔻒f����B
	//CreateEnemy(); //�G�𐶐�
}

void Enemy::Draw()const
{
	
	for (int i = 0; i < Enemynum; i++)
	{
		if (EnemyNumber[i].Enemylost == false)//�G����ʓ��AHP���c���Ă�����
		{
			switch (EnemyNumber[i].EnemyTyper) //�\������G�̉摜��switch���őI��
			{
			case 1:
				DrawRotaGraph(EnemyNumber[i].x, EnemyNumber[i].y, 1.5f, 0, Bomber_Images, TRUE); //�G�A�����@�\��
				break;
			}
			DrawRotaGraph(EnemyNumber[i].x, EnemyNumber[i].y, 1.5f, 0, Bomber_Images, TRUE); //�G�\��
		}
	}

}

void Enemy::CreateEnemy() //�G�𐶐�
{
	for (int i = 0; i < Enemynum; i++) //�G����ʊO��HP=0�Ȃ珉�����B
	{
		if (EnemyNumber[i].Enemylost == true)
		{
			EnemyNumber[i].Enemylost = false;
			EnemyNumber[i].EnemyTyper = GetRand(4);
			EnemyNumber[i].HP = 10;
			EnemyNumber[i].x = GetRand(610);
			EnemyNumber[i].y = -200; //������
			EnemyNumber[i].CollisionX = EnemyNumber[i].x + 24;
		}

	}

}

void Enemy::AliveEnemy() //�G�������Ă���̂��𔻒f����B
{
	for (int  i = 0; i < Enemynum; i++)
	{
		if (EnemyNumber[i].y > 500|| EnemyNumber[i].HP<=0)//�G�̂����W��500�����傫���Ȃ�����A���邢�͂g�o��0�ȉ��̏ꍇ
		{
			EnemyNumber[i].Enemylost = true; //�G�����S����ɐ؂�ւ�
		}
	}
}

float Enemy::CreateHit(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2) //�G�������ɁA�G���m���d�Ȃ�Ȃ��悤��
{
	//DrawRotaGraph�֐� �͎w�肵�����W������
	int L1 = x1 - w1; // ���W�Ɖ摜�̑傫�������̔���
	int R1 = x1 + w1; // ���W�Ɖ摜�̑傫���E���̔���
	int L2 = x2 - w2; // ���W�Ɖ摜�̑傫�������̔���
	int R2 = x2 + w2; // ���W�Ɖ摜�̑傫���E���̔���

	int U1 = y1 - h1;  // ��
	int D1 = y1 + h1; // ��(��+�c��)
	int U2 = y2 - h2; // ��
	int D2 = y2 + h2; // ��(��+�c��)

	if (R1 < L2 && R2 < L1 && D1 < U2 && D2 < U1)
	{
		//������Ȃ�����.
		return false;
	}
	else {
		return true;
	}

	
}

void Enemy::Hit()
{
	
}