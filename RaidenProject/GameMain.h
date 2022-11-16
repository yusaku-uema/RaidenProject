#pragma once
#include"AdstractScene.h"

class GameMain : public AdstractScene 
{
private:
public:
	
	GameMain();

	//描画以下の更新を実施する
	virtual void Update() override;

	//描画に関することを実装する
	virtual void Draw() const override;
	virtual AdstractScene* ChangeScene() override;

	void HitCheck(); //当たり判定


};
