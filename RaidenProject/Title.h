#pragma once
#include"AdstractScene.h"

class Title :public AdstractScene
{
private:
	int Title_images; //タイトル画像
	int Title_bgm; //タイトルBGM
	int Title_Drawingtime; //文字描画時間
public:
 	Title ();
	virtual void Update() override;
	virtual void Draw() const override;
	virtual AdstractScene* ChangeScene() override;
};


