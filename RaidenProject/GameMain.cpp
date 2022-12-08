#include"GameMain.h"
#include"DxLib.h"

GameMain::GameMain()
{
	//delete����̂��A�Y��Ȃ��悤��
	player = new Player(); //�v���C���[�N���X�̃f�[�^�m��
	enemy = new Enemy(); //�G�N���X�f�[�^�m��
	Stage_Images = LoadGraph("images/Stage/stage.png"); //�X�e�[�W�摜�Ǎ���

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

	///DrawGraph(0, 0, Stage_Images, FALSE); //�w�i�摜�\��

	enemy->Draw(); //�G�\��
	player->Draw(); //�v���C���[�\��
}

AdstractScene* GameMain::ChangeScene()
{
	//�V�[���؂�ւ�


	if (player->LifeCheck()==TRUE) //���C�t���A�O�ȉ��Ȃ�
	{
		delete(player);
		delete(enemy);
		//return new Gameover()
	}

	return this;
}

void GameMain::HitCheck()
{

}