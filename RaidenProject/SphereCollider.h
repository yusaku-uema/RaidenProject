#pragma once

class SphereCollider
{
private:
	float location; //���S���W
	float radius; //���a
public:
	SphereCollider();
	void  HitSphere();
	void  GetLocation();
	void  SetLocation();
};
