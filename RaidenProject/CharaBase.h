#pragma once

class CharaBase
{
private:
	float Speed;
	int Image;
public:
	CharaBase();
	virtual void Update() = 0;
	virtual void Draw() const = 0;
	virtual void Hit() = 0;
	void GetBullets(); //íeä€?
};

