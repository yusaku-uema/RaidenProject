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
	virtual AdstractScene* Update() override;
	void Draw() const override;
	void test(); //テスト他のクラスとの関数呼びだし
};


