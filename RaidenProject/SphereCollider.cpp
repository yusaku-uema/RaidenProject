#include"SphereCollider.h"
#include<math.h>

SphereCollider:: SphereCollider() 
{
	
}

bool SphereCollider::HitSphere(Location PlayerLocatio, Location EnemyLocation)
{
	float a = PlayerLocatio.x - EnemyLocation.x;
	float b = PlayerLocatio.y - EnemyLocation.y;
	float c = sqrt(a * a + b * b);
	float sum_radius = 15 + 15;


	if (c <= sum_radius)
	{
		return true;
	}
	return false;
}

Location SphereCollider::GetLocation()const 
{
	return location;
}

