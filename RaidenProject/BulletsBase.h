#pragma once
class BulletsBase
{
private:
	int damage; //与えるダメージ
	int speed; //弾の速度
public:
	BulletsBase();
	virtual void Update() = 0;
	virtual void Draw()const = 0;
	void GetDamage();
};

