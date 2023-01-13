#pragma once
#include "CharaBase.h"
#include"BulletsBase.h"
#define EnemyMax 15 //�G�̐��ő�

class Enemy :public CharaBase,public BulletsBase
{
private:
	int EnemyTime; //�G�̏o���Ԋu
	int Bomber_Images; //�����@
	int Heri_Images[3]; //�w���R�v�^�[
	int EnemyBoss_Images; //�{�X�摜
	int Jetfighter_Images; //�W�F�b�g�퓬�@
	int MesserschmittMe262; //���b�T�[�V���~�b�g�摜
	int Enemynum; //���݂̓G�̐�

	struct Enemyinformation
	{
		float x; //���W
		float y; //���W
		int HP; //�GHP
		int Point; //�G��|�������̃|�C���g
		int EnemyTyper; //�G�̎��
		bool Enemylost; //�G���o�����Ă��邩
	};
	struct Enemyinformation EnemyNumber[EnemyMax];

public:
	Enemy(); //�R���X�g���N�^
	void Update()override;
	void Draw()const override;
	void Hit()override;
	void HpCheck();
	void GetPoint();
};

