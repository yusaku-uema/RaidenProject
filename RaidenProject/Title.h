#pragma once
#include"AdstractScene.h"

class Title :public AdstractScene
{
private:
	int Title_Images; //タイトル画像
	int Title_BGM; //タイトルBGM
	int Title_Drawingtime; //文字描画時間

public:
 	Title ();
	virtual void Update() override;
	virtual void Draw() const override;
	virtual AdstractScene* ChangeScene() override;
};


