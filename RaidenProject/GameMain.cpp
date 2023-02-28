#include"GameMain.h"
#include"DxLib.h"
#include"CharaBase.h"
#include"Result.h"


//�R���X�g���N�^
GameMain::GameMain()
{
	//delete����̂��A�Y��Ȃ��悤��

	player = new Player(); //�v���C���[�N���X�̃f�[�^�m��

	for (int i = 0; i < EnemyMax; i++) 
	{
		enemy[i] = new Enemy(); //�G�N���X�f�[�^�m��
	}
	Stage_Images = LoadGraph("images/Stage/BbackgroundImage.png"); //�X�e�[�W�摜�Ǎ���
	Mileage = 0; //���s����
	BullersTime = 1;
	BullersNum = 0;
	Enemy_num = 0;
}

//�f�X�g���N�^
GameMain::~GameMain()
{
	delete player;
	delete enemy;

}
void GameMain::Update()
{

	player->Update(); //�v���C���[����

	//�G����
	for (int i = 0; i < EnemyMax; i++)
	{
		enemy[i]->Update();
	}

	//�v���C���[�̒e���G�ɓ���������
	for (int i = 0; i < EnemyMax; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (enemy[i]->HitCheck(player->GetBullet(j)))
			{
				if (player->GetRest(j) == false)
				{
					player->SetBullet(j); //�e�ۏ���
					enemy[i]->Hit(10); //HP������
					if (enemy[i]->HPCheck() == true)Enemy_num++;
				}

			}

		}
	}

	//�G�̒e�ۂɓ���������
	for (int i = 0; i < EnemyMax; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (player->HitCheck(enemy[i]->GetBullet(j)))
			{
				if (enemy[i]->GetBullet(j)->GetReset() == false)
				{
					enemy[i]->GetBullet(j)->SetReset(true);
					player->Hit(1);
				}
			}
		}
	}

	//�e�ۂ𑝂₵�čs���B
	if (BullersTime++ % 120 == 0)
	{
		BullersNum++;
	}
	if (BullersNum > 100)
	{
		BullersNum = 0;
	}


	//�e�ې���
	for (int i = 0; i < EnemyMax; i++)
	{
		for (int j = 0; j < BullersNum; j++)
		{
			enemy[i]->GetBullet(j)->SetBullers(player->GetLocation().x, player->GetLocation().y,enemy[i]->GetLocation().x, enemy[i]->GetLocation().y);
		}
	}

	//�e�ۂ̍X�V
	for (int i = 0; i < EnemyMax; i++)
	{
		for (int j = 0; j < BullersNum; j++)
		{
			enemy[i]->GetBullet(j)->Update();
		}

	}
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
		enemy[i]->Draw(); //�G�\��
		for (int  j = 0; j < 100; j++)
		{
			enemy[i]->GetBullet(j)->Draw();
		}
	}

	player->Draw(); //�v���C���[�\��
}

AdstractScene* GameMain::ChangeScene()
{
	//�V�[���؂�ւ�


	if (player->LifeCheck() == TRUE) //���C�t���A�O�ȉ��Ȃ�
	{
		return new  Result(Enemy_num);
	}

	return this;
}

void GameMain::HitCheck()
{

}

