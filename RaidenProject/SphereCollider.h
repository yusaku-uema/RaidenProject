#pragma once

struct Location
{
	float x; //���S���W(x)
	float y; //���S���W(y)
};


class SphereCollider
{ 
protected:
	int radius; //���a
	Location location;//�����蔻��
public:
	SphereCollider();
	bool HitSphere(Location location,Location location1); //�����蔻��
	Location GetLocation()const; //�v���C���[�̒��S���W���擾
	

};
