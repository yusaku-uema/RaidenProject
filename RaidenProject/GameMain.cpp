#include"GameMain.h"


GameMain::GameMain() {

}

AdstractScene* GameMain::Update() {
	player->Update();

	//�����ɃQ�[���̏���


	return this; //�����̃|�C���^�@���₷����return GameMain;
}

void GameMain::Draw()const {
	player->Draw();
}

void GameMain::HitCheck() {
}