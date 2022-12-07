#pragma once
class ItemBase
{
private:
	int speed; //‘¬“x
	int type; //Ží—Þ
public:
	ItemBase();
	virtual void Update() = 0;
	virtual void Draw()const = 0;
	void GetType();

};

