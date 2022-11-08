#pragma once
#include"AdstractScene.h"
#include"Player.h"

class GameMain : public AdstractScene 
{
private:
	player* player;

public:
	
	GameMain();

	//•`‰æˆÈ‰º‚ÌXV‚ğÀ{‚·‚é
	virtual AdstractScene* Update() override;

	//•`‰æ‚ÉŠÖ‚·‚é‚±‚Æ‚ğÀ‘•‚·‚é
	virtual void Draw() const override;

	void HitCheck(); //“–‚½‚è”»’è


};
