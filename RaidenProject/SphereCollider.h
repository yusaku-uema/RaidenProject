#pragma once

class SphereCollider
{
private:
	float location; //���S���W
	float radius; //���a
public:
	SphereCollider();
	~SphereCollider();
	float HitSphere();
	float GetLocation();
	float SetLocation();
};
