#include"GameMain.h"


GameMain::GameMain() {
	player = 0;

}

AdstractScene* GameMain::Update() {
	

	//�����ɃQ�[���̏���


	return this; //�����̃|�C���^�@���₷����return GameMain;
}

void GameMain::Draw() const {
	test->test(); //�e�X�g�A�^�C�g������֐����Ăяo���邩
}

void GameMain::HitCheck() {

}