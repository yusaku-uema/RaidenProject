#pragma once
class BulletsBase
{
private:
	int Damage; //—^‚¦‚éƒ_ƒ[ƒW
	float Speed; //’e‚Ì‘¬“x

	struct Bullets
	{
		float x; //’eŠÛÀ•W
		float y; //’eŠÛÀ•W
		bool Bulletslost; //’e‚ª‰æ–Ê‚É‚ ‚é‚©
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

