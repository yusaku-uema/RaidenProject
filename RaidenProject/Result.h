#pragma once
#include "AdstractScene.h"
class Result :public AdstractScene
{
private:
	int Result_Drawingtime; //文字描画時間
	int Enemy_num; //倒した敵

public:
	Result(int a); //コンスタラクタ
	virtual void Update() override; //描画以外
	virtual void Draw() const override; //描画のみ
	virtual AdstractScene* ChangeScene() override; //シーン切り替え
};

