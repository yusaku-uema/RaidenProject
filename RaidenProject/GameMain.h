#pragma once
#include"AdstractScene.h"
#include"Player.h"

class GameMain : public AdstractScene 
{
private:
	player* player;

public:
	
	GameMain();

	//描画以下の更新を実施する
	virtual AdstractScene* Update() override;

	//描画に関することを実装する
	virtual void Draw() const override;

	void HitCheck(); //当たり判定


};
