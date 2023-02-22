#pragma once
#include"SphereCollider.h"

class BulletsBase :public SphereCollider
{
protected:
	int Damage; //与えるダメージ
	int Shooting_Time; //弾の発射間隔
	float Speed; //弾の速度
	bool Reset; //リセットフラグ（弾丸を打ち出す初期設定)

public:
	BulletsBase();
	virtual void Update() = 0;
	virtual void Draw()const = 0;
	int  GetDamage();
	float GetBulletsSpeed();
	
	void SetReset(bool a)
	{
		Reset = a;
	}
		bool GetReset()
	{
		return Reset;
	}
};

