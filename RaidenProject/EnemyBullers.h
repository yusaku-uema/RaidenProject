#pragma once
#include "BulletsBase.h"
class EnemyBullers : public BulletsBase
{
private:
	bool Reset; //���Z�b�g�t���O�i�e�ۂ�ł��o�������ݒ�)
	bool Set; //�e�ۏ�������
	int Interval; //���ˊԊu
	int Time;
	float bullet_speed_x;
	float bullet_speed_y;

public:
	EnemyBullers();
	void SetBullers(float x, float y, float Enemy_x, float Enemy_y);

	void Update();
	void Draw()const;
	float GetBullets_Y();
	int  GetDamage();
	float GetBulletsSpeed();
	void SetReset(bool a);
	bool GetReset();
};


