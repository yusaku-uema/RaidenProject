#pragma once

class SphereCollider
{

private:
	int location; //���S���W
	int radius; //���a

public:
	SphereCollider();
	void  HitSphere();
	void  GetLocation();
	void  SetLocation();
};
