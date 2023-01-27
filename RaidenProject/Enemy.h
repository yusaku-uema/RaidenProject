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
		float CollisionX;
		float CollisionY;
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
	float CreateHit(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2); //�G�������ɁA�G���m���d�Ȃ�Ȃ��悤��
	void CreateEnemy(); //�G����
	void AliveEnemy(); //�G�������Ă���̂��i��ʊO�AHP���Ȃ��Ȃ����j
	void HPCheck();
	void GetPoint();
};

