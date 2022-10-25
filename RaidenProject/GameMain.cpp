#include"GameMain.h"


GameMain::GameMain() {
	player = 0;

}

AdstractScene* GameMain::Update() {
	
	return this;
}

void GameMain::Draw() const {
	test->test();
}

void GameMain::HitCheck() {

}