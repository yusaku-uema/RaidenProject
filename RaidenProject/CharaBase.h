#pragma once

class CharaBase
{
private:
	//ポインタ配列
	//int* bullets[5];
	float Speed;
	int  Bullest_image; //弾丸弾
public:
	virtual void Update() = 0;
	virtual void Draw() const = 0;
	virtual void Hit() = 0;
};

