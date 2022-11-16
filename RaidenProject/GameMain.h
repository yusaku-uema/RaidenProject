#pragma once
#include"AdstractScene.h"

class GameMain : public AdstractScene 
{
private:
public:
	
	GameMain();

	//•`‰æˆÈ‰º‚ÌXV‚ğÀ{‚·‚é
	virtual void Update() override;

	//•`‰æ‚ÉŠÖ‚·‚é‚±‚Æ‚ğÀ‘•‚·‚é
	virtual void Draw() const override;
	virtual AdstractScene* ChangeScene() override;

	void HitCheck(); //“–‚½‚è”»’è


};
