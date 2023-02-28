#include"SphereCollider.h"
#include<math.h>

SphereCollider:: SphereCollider() 
{
	radius = 5;
}

bool SphereCollider::HitSphere(SphereCollider* spherecollider)const
{
	bool ret = false;//返り値
	float distance;	//中心座標の距離

	//中心座標の距離の計算
	distance = sqrtf(powf(spherecollider->GetLocation().x - location.x, 2) + powf(spherecollider->GetLocation().y - location.y, 2));

	if (distance < radius + spherecollider->GetRadius()) //当たり判定
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

