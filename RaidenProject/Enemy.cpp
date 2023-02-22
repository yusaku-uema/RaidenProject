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
	//�G�̈ʒu�����ɂ��炵�Ă���
	y=  y+ 1;

	AliveEnemy(); //�G�������Ă���̂��𔻒f����B

		CreateEnemy(); //�G�𐶐�
}

void Enemy::Draw()const
{

	
		if (Enemylost == false)//�G����ʓ��AHP���c���Ă�����
		{
			DrawRotaGraph(x, y, 1.5f, 0, Bomber_Images, TRUE); //�G�\��
		}

}

void Enemy::CreateEnemy() //�G�𐶐�
{
	
		if (Enemylost == true)
		{
			Enemylost = false;
			EnemyTyper = GetRand(4);
			HP = 10;
			x = GetRand(610);
			y = GetRand(-210)-110; //-110����-210�̃����_��
		}
}

void Enemy::AliveEnemy() //�G�������Ă���̂��𔻒f����B
{
	
		if (y > 500 || HP <= 0)//�G�̂����W��500�����傫���Ȃ�����A���邢�͂g�o��0�ȉ��̏ꍇ
		{
			Enemylost = true; //�G�����S����ɐ؂�ւ�
		}
}


void Enemy::Hit()
{

}

bool Enemy::HitCheck(Player* player)
{
	return false;
}