#pragma once
#include "BulletsBase.h"

class PlayerBullers :public BulletsBase
{
private:
	bool Reset; //���Z�b�g�t���O�i�e�ۂ�ł��o�������ݒ�)

public:
	PlayerBullers();
	
	void Update()override;
	void Draw()const;
	Location GetBullets();
	void SetBullers(float x, float y);
	void SetReset(bool a);
	bool GetReset();
};


