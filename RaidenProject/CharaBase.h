#pragma once
#include"PlayerBullers.h"

class CharaBase :public SphereCollider
{
protected:
	PlayerBullers* Playerbullets[100];  //’e‚Ì”z—ñ
private:
	float Speed;
	int Image;
public:
	CharaBase();
	virtual void Update() = 0;
	virtual void Draw() const = 0;
	virtual void Hit() = 0;
};

