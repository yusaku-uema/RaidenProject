#pragma once
#include "CharaBase.h"
#include"BulletsBase.h"
#define EnemyMax 6 //�G�̐��ő�

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


class Enemy :public CharaBase,public BulletsBase
{
private:
	int EnemyTime; //�G�̏o���Ԋu
	int Bomber_Images; //�����@
	int EnemyBoss_Images; //�{�X�摜
	int Enemynum; //���݂̓G�̐�

	
	struct Enemyinformation EnemyNumber[EnemyMax];

public:
	Enemy(); //�R���X�g���N�^
	void Update()override;
	void Draw()const override;
	void Hit()override;
	//float CreateHit(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2); //�G�������ɁA�G���m���d�Ȃ�Ȃ��悤��
	void CreateEnemy(); //�G����
	void AliveEnemy(); //�G�������Ă���̂��i��ʊO�AHP���Ȃ��Ȃ����j
	void HPCheck();
	void GetPoint();
};

