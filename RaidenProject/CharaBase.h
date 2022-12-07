#pragma once

class CharaBase
{
private:
	int Speed;
	int Bullest_image; //íeä€íe
public:
	virtual void Update() = 0;
	virtual void Draw() const = 0;
	virtual void Hit() = 0;
};

