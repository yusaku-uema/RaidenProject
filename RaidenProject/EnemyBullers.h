#pragma once
#include "BulletsBase.h"
class EnemyBullers : public BulletsBase
{
private:
	bool Reset; //リセットフラグ（弾丸を打ち出す初期設定)
	bool Set; //弾丸初期処理
	float bullet_speed_x;
	float bullet_speed_y;

public:
	EnemyBullers();
	void SetBullers(float x,float y);

	void Update()override;
	void Draw()const;
	float GetBullets_Y();
	int  GetDamage();
	float GetBulletsSpeed();
	//void SetBullers(float x, float y);
	void SetReset(bool a);
	bool GetReset();
};

