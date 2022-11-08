#include"GameMain.h"


GameMain::GameMain() {

}

AdstractScene* GameMain::Update() {
	player->Update();

	//ここにゲームの処理


	return this; //自分のポインタ　見やすく→return GameMain;
}

void GameMain::Draw()const {
	player->Draw();
}

void GameMain::HitCheck() {
}