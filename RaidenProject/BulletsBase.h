#pragma once

struct Bullets 
	{
		float x; //’eŠÛÀ•W
		float y; //’eŠÛÀ•W
		bool Bulletslost; //’e‚ª‰æ–Ê‚É‚ ‚é‚©
	};
	
class BulletsBase
{
private:
	int Damage; //—^‚¦‚éƒ_ƒ[ƒW
	float Speed; //’e‚Ì‘¬“x
public:
	BulletsBase();
	virtual void Update() = 0;
	virtual void Draw()const = 0;
	int  GetDamage();
	float GetBulletsSpeed();
};

