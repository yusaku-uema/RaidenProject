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
	int GetRadius() const;
	bool HitSphere(SphereCollider* spherecollider)const; //�����蔻��
	Location GetLocation(); //�v���C���[�̒��S���W���擾
	

};
