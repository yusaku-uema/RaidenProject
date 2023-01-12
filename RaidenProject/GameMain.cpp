#include"GameMain.h"
#include"DxLib.h"


//����
//�������̕s�����͓��ꂷ��ق����悢
//��@�@if(a < b)  < �̌����œ��ꂷ��@�L�q��01/11��4���Ԗ�
//����ȍ~�� �s�����̌������@<�@�̌����ł�낵���B



GameMain::GameMain()
{
	//delete����̂��A�Y��Ȃ��悤��
	player = new Player(); //�v���C���[�N���X�̃f�[�^�m��
	enemy = new Enemy(); //�G�N���X�f�[�^�m��
	Stage_Images = LoadGraph("images/Stage/BbackgroundImage.png"); //�X�e�[�W�摜�Ǎ���
	Mileage = 0; //���s����

}

void GameMain::Update()
{
	//�����ɃQ�[���̏���

	player->Update(); //�v���C���[����
	enemy->Update(); //�G����


	//�X�e�[�W�X�N���[������
	Mileage += player->GetPlayerSpeed();

}

void GameMain::Draw()const
{
	
	//�X�e�[�W�`��
	DrawGraph(0, Mileage % 480 - 480, Stage_Images, FALSE);//�摜�������Ă���悤�Ɍ�����悤�ɕ`��
	DrawGraph(0, Mileage % 480, Stage_Images, FALSE);//�`��

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