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
	//�G�̈ʒu�����ɂ��炵�Ă���
	location.y += 1;

	AliveEnemy(); //�G�������Ă���̂��𔻒f����B

	CreateEnemy(); //�G�𐶐�
}

void Enemy::Draw()const
{

	DrawRotaGraph(location.x, location.y, 1.5f, 0, Bomber_Images, TRUE); //�G�\��

}

void Enemy::CreateEnemy() //�G�𐶐�
{

	if (Enemylost == true)
	{
		EnemyTyper = GetRand(4);
		HP = 20;
		location.x = GetRand(570) + 50;
		location.y = GetRand(-100) - 50; //-110����-210�̃����_��
		Enemylost = false;
	}
}

void Enemy::AliveEnemy() //�G�������Ă���̂��𔻒f����B
{

	if (location.y > 500 || HP <= 0)//�G�̂����W��500�����傫���Ȃ�����A���邢�͂g�o��0�ȉ��̏ꍇ
	{
		Enemylost = true; //�G�����S����ɐ؂�ւ�
	}
}


void Enemy::Hit(int a)
{
	HP -= a;
}


bool Enemy::HitCheck(PlayerBullers* playerbullers)
{
	bool ret = false; //�߂�l

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



