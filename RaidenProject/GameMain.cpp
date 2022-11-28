#include"GameMain.h"

GameMain::GameMain() {
	
}

void  GameMain::Update() {
	
	player->Update(); 
	//‚±‚±‚ÉƒQ[ƒ€‚Ìˆ—

}

void GameMain::Draw()const {
	player->Draw();
}

AdstractScene* GameMain::ChangeScene()
{
	return this;
}

void GameMain::HitCheck() {
}