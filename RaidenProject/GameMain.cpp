#include"GameMain.h"


GameMain::GameMain() {
	player = 0;

}

AdstractScene* GameMain::Update() {
	
	return this;
}

void GameMain::Draw() const {
	test->test(); //テスト、タイトルから関数を呼び出せるか
}

void GameMain::HitCheck() {

}