#pragma once
#include"BulletsBase.h"

class CharaBase : public BulletsBase
{
private:
	struct Bullets PlayerBullets[100]; 
	struct Bullets* bullets = PlayerBullets;
	float Speed;
	int Image;
public:
	CharaBase();
	virtual void Update() = 0;
	virtual void Draw() const = 0;
	virtual void Hit() = 0;
	float GetBullets_X(int i)const; //弾丸座標取得  //Draw() const で呼び出すにはGetの方もconstに
	void SetBullets_X(int i, float j); //弾丸座標変更
	float GetBullets_Y(int i)const; //弾丸座標取得
	void SetBullets_Y(int i, float j); //弾丸座標変更
	bool GetBullets_flg(int i)const; //弾丸が画面外にいるのか
	void SetBullets_flg(int i, bool); //弾丸が存在しているのかのフラグ
};

