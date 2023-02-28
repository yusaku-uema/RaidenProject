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
	int GetRadius() const;
	bool HitSphere(SphereCollider* spherecollider)const; //当たり判定
	Location GetLocation(); //プレイヤーの中心座標を取得
	

};
