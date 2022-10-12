#pragma once

#pragma once
#include"AdstractScene.h"

class GameMain : public AdstractScene 
{
private:

public:
	//デストラクタ
	virtual ~GameMain() {};

	//描画以下の更新を実施する
	virtual AdstractScene* Update() override;

	//描画に関することを実装する
	virtual void Draw() const override;


};
