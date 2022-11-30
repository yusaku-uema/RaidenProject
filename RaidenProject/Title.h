#pragma once
#include"AdstractScene.h"

class Title :public AdstractScene
{
private:
	int Title_Images; //タイトル画像
	int Title_BGM; //タイトルBGM
	int Title_Drawingtime; //文字描画時間

public:
	Title(); //コンスタラクタ
	virtual void Update() override; //描画以外
	virtual void Draw() const override; //描画のみ
	virtual AdstractScene* ChangeScene() override; //シーン切り替え
};


