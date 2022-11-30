#include"GameMain.h"
#include"DxLib.h"

GameMain::GameMain()
{
	player = new Player(); //�v���C���[�N���X�̃f�[�^�m��
	Stage_Images = LoadGraph("images/Stage/stage.png"); 
}

void GameMain::Update()
{
	//�����ɃQ�[���̏���

	player->Update(); 

}

void GameMain::Draw()const
{
	//�`��̂�

	DrawGraph(0, 0, Stage_Images, FALSE); //�w�i�摜�\��

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