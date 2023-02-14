#pragma once
#include"CharaBase.h"
#include"BulletsBase.h"
#include"SphereCollider.h"
#define EnemyMax 6 //�G�̐��ő�


class Enemy :public CharaBase,public SphereCollider
{
private:
	float x; //�G���W
	float y; //�G���W
	int HP; //�GHP
	int Point; //�G��|�������̃|�C���g
	int EnemyTyper; //�G�̎��
	int EnemyTime; //�G�̏o���Ԋu
	int Bomber_Images; //�����@
	bool Enemylost; //�G���o�����Ă��邩
	

public:
	Enemy(); //�R���X�g���N�^
	void Update()override;
	void Draw()const override;
	void Hit()override;
	void CreateEnemy(); //�G����
	void AliveEnemy(); //�G�������Ă���̂��i��ʊO�AHP���Ȃ��Ȃ����j
	void HPCheck();
	void GetPoint();
};

