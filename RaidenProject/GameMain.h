#pragma once
#include"AdstractScene.h"
#include"Player.h"

class GameMain : public AdstractScene 
{
private:
	Player *player;
public:
	
	GameMain();

	//描画以下の更新を実施する
	void Update() override;

	//描画に関することを実装する
	void Draw() const override;
	AdstractScene* ChangeScene() override;

	void HitCheck(); //当たり判定


};
