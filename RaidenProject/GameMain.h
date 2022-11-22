#pragma once
#include"AdstractScene.h"
#include"Player.h"

class GameMain : public AdstractScene 
{
private:
	Player *player;
public:
	
	GameMain();

	//•`‰æˆÈ‰º‚ÌXV‚ğÀ{‚·‚é
	void Update() override;

	//•`‰æ‚ÉŠÖ‚·‚é‚±‚Æ‚ğÀ‘•‚·‚é
	void Draw() const override;
	AdstractScene* ChangeScene() override;

	void HitCheck(); //“–‚½‚è”»’è


};
