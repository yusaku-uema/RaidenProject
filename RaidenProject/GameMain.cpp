#include"GameMain.h"
#include"DxLib.h"

GameMain::GameMain()
{
	player = new Player(); //�v���C���[�N���X�̃f�[�^�m��
	enemy = new Enemy();
	Stage_Images = LoadGraph("images/Stage/stage.png"); 
}

void GameMain::Update()
{
	//�����ɃQ�[���̏���

	player->Update(); //�v���C���[����
	enemy->Update(); //�G����

}

void GameMain::Draw()const
{
	//�`��̂�

	DrawGraph(0, 0, Stage_Images, FALSE); //�w�i�摜�\��

	enemy->Draw(); //�G�\��
	player->Draw(); //�v���C���[�\��
}

AdstractScene* GameMain::ChangeScene()
{
	//�V�[���؂�ւ�
	return this;
}

void GameMain::HitCheck()
{

}