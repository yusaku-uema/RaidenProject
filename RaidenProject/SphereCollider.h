#pragma once

struct Location
{
	float x; //中心座標(x)
	float y; //中心座標(y)
};


class SphereCollider
{ 
protected:
	int radius; //半径
	Location location;//当たり判定
public:
	SphereCollider();
	bool HitSphere(Location location,Location location1); //当たり判定
	Location GetLocation()const; //プレイヤーの中心座標を取得
	

};
