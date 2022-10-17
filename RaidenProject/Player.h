#pragma once
#include"AdstractScene.h"

class player :public AdstractScene
{
private:
	int score; //スコア
	int life; //残り残機
public:
	player();
	~player();
	virtual AdstractScene* Update()override;
	virtual void Draw()const override; 
};
