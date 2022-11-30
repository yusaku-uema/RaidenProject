#include"GameMain.h"

GameMain::GameMain()
{

}

void GameMain::Update()
{
	//‚±‚±‚ÉƒQ[ƒ€‚Ìˆ—

	player->Update();

}

void GameMain::Draw()const
{
	//•`‰æ‚Ì‚İ
	player->Draw();
}

AdstractScene* GameMain::ChangeScene()
{
	//ƒV[ƒ“Ø‚è‘Ö‚¦
	return this;
}

void GameMain::HitCheck()
{

}