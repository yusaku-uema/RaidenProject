#pragma once
#include "ItemBase.h"
#include"Player.h"

class Recovery : public ItemBase
{
private:
	int images; //‰æ‘œ
	bool Reset; //ƒŠƒZƒbƒg
public:
	Recovery();
	void Update();
	 void Draw()const;
	 void SetReset();
	 bool HitCheck(Player* player);
	 
};

