#pragma once

class SphereCollider
{
	//�����蔻��
private:
	int location; //���S���W
	int radius; //���a

public:
	SphereCollider();
	void  HitSphere();
	int  GetLocation();
	void  SetLocation();
};
