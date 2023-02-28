#pragma once
#include"CharaBase.h"
#include"BulletsBase.h"
#include"Player.h"
#define EnemyMax 8 //�G�̐��ő�


class Enemy :public CharaBase
{
private:
	int HP; //�GHP
	int Interval; //���ˊԊu
	int Bullers_num; //�e�ې�
	int Point; //�G��|�������̃|�C���g
	int EnemyTyper; //�G�̎��
	int EnemyTime; //�G�̏o���Ԋu
	int Bomber_Images; //�����@
	bool Enemylost; //�G���o�����Ă��邩
	bool EnemyHit; //�U����H��������B


public:
	Enemy(); //�R���X�g���N�^
	void Update()override;
	void Draw()const override;
	void Hit(int a);
	void CreateEnemy(); //�G����
	void Bullers();
	void AliveEnemy(); //�G�������Ă���̂��i��ʊO�AHP���Ȃ��Ȃ����j
	void HPCheck();
	void GetPoint();
	float Enemy_Y();
	int Getnum();
	bool HitCheck(PlayerBullers* playerbullers); //�U�����󂯂��̂�
	EnemyBullers* GetBullet(int i)const;

};
