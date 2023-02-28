#pragma once
#include"PlayerBullers.h"
#include"EnemyBullers.h"

class CharaBase :public SphereCollider
{
protected:
	PlayerBullers* Playerbullers[100];  //’e‚Ì”z—ñ
	EnemyBullers* Enemybullers[100]; //’e‚Ì”z—ñ

private:
	float Speed;
	int Image;
public:
	CharaBase();
	virtual void Update() = 0;
	virtual void Draw() const = 0;
	virtual void Hit(int a) = 0;
};

