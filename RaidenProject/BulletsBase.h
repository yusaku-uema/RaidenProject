#pragma once
class BulletsBase
{
private:
	int Damage; //与えるダメージ
	float Speed; //弾の速度

	struct Bullets
	{
		float x; //弾丸座標
		float y; //弾丸座標
		bool Bulletslost; //弾が画面にあるか
	};
	struct Bullets PlayerBullets[100];
	struct Bullets EnemyBullets[100];
	

public:
	BulletsBase();
	virtual void Update() = 0;
	virtual void Draw()const = 0;
	int  GetDamage();
	float GetBulletsSpeed();
};

