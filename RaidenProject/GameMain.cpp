#include"GameMain.h"
#include"DxLib.h"


//����
//�������̕s�����͓��ꂷ��ق����悢
//��@�@if(a < b)  < �̌����œ��ꂷ��@�L�q��01/11��4���Ԗ�
//����ȍ~�� �s�����̌������@<�@�̌����ł�낵���B


//�R���X�g���N�^
GameMain::GameMain()
{
	//delete����̂��A�Y��Ȃ��悤��
	player = new Player(); //�v���C���[�N���X�̃f�[�^�m��
	for (int i = 0; i < EnemyMax; i++) {
		enemy[i] = new Enemy(); //�G�N���X�f�[�^�m��
	}
	Stage_Images = LoadGraph("images/Stage/BbackgroundImage.png"); //�X�e�[�W�摜�Ǎ���
	Mileage = 0; //���s����

}

//�f�X�g���N�^
GameMain::~GameMain()
{
	delete player;
	for (int i = 0; i < EnemyMax; i++) {
		delete enemy[i];
	}
	
}
void GameMain::Update()
{
	//�����ɃQ�[���̏���

	player->Update(); //�v���C���[����
	//�G����
	for (int i = 0; i < EnemyMax; i++) {
		enemy[i]->Update();
	}
	 
	//�X�e�[�W�X�N���[������
	Mileage += player->GetPlayerSpeed();

}

void GameMain::Draw()const
{
	
	//�X�e�[�W�`��
	DrawGraph(0, Mileage % 480 - 480, Stage_Images, FALSE);//�摜�������Ă���悤�Ɍ�����悤�ɕ`��
	DrawGraph(0, Mileage % 480, Stage_Images, FALSE);//�`��
	for (int i = 0; i < EnemyMax; i++) {
		enemy[i]->Draw(); //�G�\��
	}
	
	player->Draw(); //�v���C���[�\��
}

AdstractScene* GameMain::ChangeScene()
{
	//�V�[���؂�ւ�


	if (player->LifeCheck()==TRUE) //���C�t���A�O�ȉ��Ȃ�
	{
		//return new Gameover()
	}

	return this;
}

void GameMain::HitCheck()
{
	
}

