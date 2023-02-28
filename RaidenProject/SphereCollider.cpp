#include"SphereCollider.h"
#include<math.h>

SphereCollider:: SphereCollider() 
{
	radius = 5;
}

bool SphereCollider::HitSphere(SphereCollider* spherecollider)const
{
	bool ret = false;//�Ԃ�l
	float distance;	//���S���W�̋���

	//���S���W�̋����̌v�Z
	distance = sqrtf(powf(spherecollider->GetLocation().x - location.x, 2) + powf(spherecollider->GetLocation().y - location.y, 2));

	if (distance < radius + spherecollider->GetRadius()) //�����蔻��
	{
		ret = true;
	}

	return ret;
}

int SphereCollider::GetRadius()const
{
	return radius;
}

Location SphereCollider::GetLocation()
{
	return location;
}

