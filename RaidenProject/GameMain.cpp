#include"GameMain.h"

GameMain::GameMain() {
	
}

void  GameMain::Update() {
	
	player->Update(); 
	//ここにゲームの処理

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