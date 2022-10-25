#include"GameMain.h"


GameMain::GameMain() {
	player = 0;

}

AdstractScene* GameMain::Update() {
	

	//ここにゲームの処理


	return this; //自分のポインタ　見やすく→return GameMain;
}

void GameMain::Draw() const {
	test->test(); //テスト、タイトルから関数を呼び出せるか
}

void GameMain::HitCheck() {

}