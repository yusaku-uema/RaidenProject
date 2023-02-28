#include"GameMain.h"
#include"DxLib.h"
#include"CharaBase.h"


//�R���X�g���N�^
GameMain::GameMain()
{
	//delete����̂��A�Y��Ȃ��悤��

	player = new Player(); //�v���C���[�N���X�̃f�[�^�m��

	//for (int i = 0; i < EnemyMax; i++) {
		//enemy[i] = new Enemy(); //�G�N���X�f�[�^�m��
	//}
	enemy = new Enemy();
	Stage_Images = LoadGraph("images/Stage/BbackgroundImage.png"); //�X�e�[�W�摜�Ǎ���
	Mileage = 0; //���s����

}

//�f�X�g���N�^
GameMain::~GameMain()
{
	delete player;
	delete enemy;

}
void GameMain::Update()
{
	//�����ɃQ�[���̏���

	player->Update(); //�v���C���[����
	//�G����
	/*for (int i = 0; i < EnemyMax; i++)
	{
		enemy[i]->Update();
	}*/
	enemy->Update();

	//�v���C���[�̒e���G�ɓ���������
	//for (int i = 0; i < EnemyMax; i++)
	//{
	//	for (int j = 0; j < 100; j++)
	//	{
	//		if (enemy[i]->HitCheck(player->GetBullet(j)))
	//		{
	//			if (player->GetRest(j) == false)
	//			{
	//				player->SetBullet(j); //�e�ۏ���
	//				enemy[i]->Hit(10); //HP������
	//			}

	//		}

	//	}
	//}

	//�X�e�[�W�X�N���[������
	Mileage += player->GetPlayerSpeed();



}

void GameMain::Draw()const
{

	//�X�e�[�W�`��
	DrawGraph(0, Mileage % 480 - 480, Stage_Images, FALSE);//�摜�������Ă���悤�Ɍ�����悤�ɕ`��
	DrawGraph(0, Mileage % 480, Stage_Images, FALSE);//�`��
	for (int i = 0; i < EnemyMax; i++)
	{
		enemy->Draw(); //�G�\��
	}

	player->Draw(); //�v���C���[�\��
}

AdstractScene* GameMain::ChangeScene()
{
	//�V�[���؂�ւ�


	if (player->LifeCheck() == TRUE) //���C�t���A�O�ȉ��Ȃ�
	{
		//return new Gameover()
	}

	return this;
}

void GameMain::HitCheck()
{

}

