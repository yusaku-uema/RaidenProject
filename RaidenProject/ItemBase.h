#pragma once
#include"SphereCollider.h"

class ItemBase:public SphereCollider
{
protected:
	int speed; //‘¬“x
	int type; //Ží—Þ
public:
	ItemBase();
	virtual void Update() = 0;
	virtual void Draw()const = 0;
	int GetType();

};

