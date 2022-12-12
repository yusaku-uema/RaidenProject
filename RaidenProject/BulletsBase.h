#pragma once
class BulletsBase
{
private:
	int Damage; //与えるダメージ
	float Speed; //弾の速度
public:
	BulletsBase();
	virtual void Update() = 0;
	virtual void Draw()const = 0;
	int  GetDamage();
};

