#pragma once
#include "ItemBase.h"
#include"Player.h"

class Recovery : public ItemBase
{
private:
	int images; //�摜
	bool Reset; //���Z�b�g
public:
	Recovery();
	void Update();
	 void Draw()const;
	 void SetReset();
	 bool HitCheck(Player* player);
	 
};
