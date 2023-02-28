#pragma once
#include "BulletsBase.h"

class PlayerBullers :public BulletsBase
{
private:
	bool Reset; //リセットフラグ（弾丸を打ち出す初期設定)

public:
	PlayerBullers();
	
	void Update()override;
	void Draw()const;
	Location GetBullets();
	void SetBullers(float x, float y);
	void SetReset(bool a);
	bool GetReset();
};


