#include"GameMain.h"

GameMain::GameMain()
{

}

void GameMain::Update()
{
	//�����ɃQ�[���̏���

	player->Update();

}

void GameMain::Draw()const
{
	//�`��̂�
	player->Draw();
}

AdstractScene* GameMain::ChangeScene()
{
	//�V�[���؂�ւ�
	return this;
}

void GameMain::HitCheck()
{

}