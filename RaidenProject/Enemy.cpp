#include "Enemy.h"
#include"DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>

Enemy::Enemy()
{
	Enemy_X = 310; //�K���A�̂��ɒ���
	Enemy_Y = 120; //�K���A�̂��ɒ���
	HP = 10; //�K���A�̂��ɒ���
	Point = 20; //�K���A�̂��ɒ���
	Bomber_Images = LoadGraph("images/Enemy/bomber.png");
}

void Enemy::Update()
{
	//�G�����������A���͓����Ȃ�
}

void Enemy::Draw()const
{
	DrawRotaGraph(Enemy_X, Enemy_Y, 1.5f, 0, Bomber_Images, TRUE); //�G�\��
}

void Enemy::Hit()
{

}