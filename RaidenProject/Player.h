#pragma once
#include"AdstractScene.h"

class player :public AdstractScene
{
private:
	int score; //�X�R�A
	int life; //�c��c�@
public:
	player();
	~player();
	virtual AdstractScene* Update()override;
	virtual void Draw()const override; 
};
