#pragma once
#include "BulletsBase.h"

class PlayerBullers :public BulletsBase
{

public:
	PlayerBullers();
	PlayerBullers(float x, float y);
	void Update()override;
	void Draw()const;
	Location GetBullets();
	int  GetDamage();
	float GetBulletsSpeed();
};


