#pragma once

class SphereCollider
{
private:
	float location; //’†SÀ•W
	float radius; //”¼Œa
public:
	SphereCollider();
	~SphereCollider();
	float HitSphere();
	float GetLocation();
	float SetLocation();
};
