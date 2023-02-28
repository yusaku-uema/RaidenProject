#pragma once
#include "BulletsBase.h"
class EnemyBullers : public BulletsBase
{
private:
	bool Reset; //リセットフラグ（弾丸を打ち出す初期設定)
	bool Set; //弾丸初期処理
	int Interval; //発射間隔
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


