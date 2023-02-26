#include"Player.h"
#include"DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>

#define NORMAL 2.2; //�v���C���[�̒ʏ�ړ�
#define ATTACK 2.2; //�U����Ԃ̈ړ����x�@�@�i�x�����邩�A�������͂��̂܂܂������Ă���j

Player::Player()
{
	AX = 0;
	AY = 0;
	Image_time = 0;
	Score = 0;
	Life = 0;
	location.x = 310;
	location.y = 240;
	BulletNum = 0;
	Player_Type = 0;
	LoadDivGraph("images/Player/Zerofighter plane.png", 4, 32, 1, 32, 32, Player_images);
	g_KeyFlg = 0;
	g_NowKey = 0;
	g_OldKey = 0;
	Shooting_Flag = FALSE;
	Player_Speed = NORMAL;
	Right = FALSE;
	Left = FALSE;
	Invincible_Flag = FALSE;
	DrawBullet = 0;
	Shooting_Time = 1;

	for (int i = 0; i < 100; i++)
	{
		Playerbullets[i] = new PlayerBullers();
	}
}

Player::~Player()
{
	delete Playerbullets;
}


void Player::Update()
{

	g_OldKey = g_NowKey;
	g_NowKey = GetJoypadInputState(DX_INPUT_PAD1); //�p�b�g���͎擾
	g_KeyFlg = g_NowKey & ~g_OldKey;

	GetJoypadAnalogInput(&AX, &AY, DX_INPUT_PAD1); //�X�e�b�N���͎擾
	ShootBullet();
	Operation(); //�v���C���[����
	ImageSwitching(); //�v���C���[�摜�؂�ւ�

}

void Player::Draw() const
{

	if (g_KeyFlg & PAD_INPUT_4) //RB�{�^�������������Ă��邩�B
	{
		DrawFormatString(320, 240, 0xFFFFFF, "yusaku");
	}

	if (Left == TRUE) //���ɌX���Ă���摜
	{
		DrawRotaGraph(location.x, location.y, 1.5f, (M_PI / 180) * -45, Player_images[Player_Type], TRUE); //�摜�A���ɌX��
	}
	else if (Right == TRUE) //�E�ɌX���Ă���摜
	{
		DrawRotaGraph(location.x, location.y, 1.5f, (M_PI / 180) * 45, Player_images[Player_Type], TRUE); //�摜�A�E�ɌX��
	}

	else
	{
		DrawRotaGraph(location.x, location.y, 1.5f, 0, Player_images[Player_Type], TRUE); //�摜�^������
	}

	for (int i = 0; i < 100; i++)
	{
		if (Playerbullets[i]->GetReset()!=true)
		{
			Playerbullets[i]->Draw();
		}
	}

}

void Player::Bullet()
{
	if (Shooting_Time++ % 20 == 0)//�e�۔��ˊԊu
	{
		if (BulletNum < 100)
		{
			BulletNum++;
		}
		else
		{
			BulletNum = 0;
		}


		if (Playerbullets[BulletNum]->GetReset()==true)
		{
			Playerbullets[BulletNum]->SetBullers(location.x, location.y - 18);
		}

	}

}

void  Player::ShootBullet() //�e�̓���
{
	for (int i = 0; i < 100; i++)
	{
		if (Playerbullets[i]->GetReset() != true)
		{
			Playerbullets[i]->Update();
		}
	}
}


void  Player::Operation() //�v���C���[����
{

	if (g_KeyFlg && PAD_INPUT_4) //RB�{�^�������������Ă��邩�B
	{
		Invincible_Flag = TRUE;
		DrawFormatString(320, 240, 0xFFFFFF, "�{��");
	}

	if (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_5) //LB�{�^�������������Ă��邩�B
	{
		Shooting_Flag = TRUE; //�ˌ��J�n
		Player_Speed = ATTACK; //�ړ����x�ቺ
		Bullet();
	}
	else
	{
		Shooting_Flag = FALSE; //�ʏ���
		Player_Speed = NORMAL; //���q���x�ɖ߂�
	}
	if (location.x < 640 - 32 && location.y < 480 - 32 && location.x > 32 && location.y > 32)
	{
		if (AX > 0 && AY > 0) //�X�e�b�N���E&���ɓ|��Ă�����
		{
			location.x += Player_Speed;
			location.y += Player_Speed;
			Right = TRUE;
			Left = FALSE;
		}

		else if (AX > 0 && AY < 0) //�X�e�b�N���E&��ɓ|��Ă�����
		{
			location.x +=  Player_Speed;
			location.y -=  Player_Speed;
			Right = TRUE;
			Left = FALSE;
		}

		else if (AX < 0 && AY < 0) //�X�e�b�N����&��ɓ|��Ă�����
		{
			location.x -= Player_Speed;
			location.y -= Player_Speed;
			Left = TRUE;
			Right = FALSE;
		}

		else if (AX < 0 && AY > 0) //�X�e�b�N����&���ɓ|��Ă�����
		{
			location.x -=  Player_Speed;
			location.y += Player_Speed;
			Left = TRUE;
			Right = FALSE;
		}

		else if (AY > 0) //�X�e�b�N�����ɓ|��Ă�����
		{
			location.y +=Player_Speed;
			Right = FALSE;
			Left = FALSE;
		}

		else if (AY < 0) //�X�e�b�N����ɓ|��Ă�����
		{
			location.y -=Player_Speed;
			Right = FALSE;
			Left = FALSE;
		}

		else if (AX > 0) //�X�e�b�N���E�ɓ|��Ă�����
		{
			location.x += Player_Speed;
			Right = TRUE;
			Left = FALSE;
		}

		else if (AX < 0) //�X�e�b�N�����ɓ|��Ă�����
		{
			location.x -= Player_Speed;
			Left = TRUE;
			Right = FALSE;
		}

		else //�������삵�Ă��Ȃ��B
		{
			Right = FALSE;
			Left = FALSE;
		}
	}

	if (location.x <= 32) //��ʊO�ɍs��������W��߂�
	{
		location.x = 34;
	}

	if (location.x >= 608) //��ʊO�ɍs��������W��߂�
	{
		location.x = 606;
	}

	if (location.y >= 448) //��ʊO�ɍs��������W��߂��B
	{
		location.y = 446;
	}

	if (location.y <= 32)//��ʊO�ɍs��������W��߂��B
	{
		location.y = 34;
	}
}

void  Player::ImageSwitching() //�v���C���[�摜�؂�ւ�
{
	if (++Image_time >= 5)
	{
		if (Shooting_Flag == FALSE) //�ˌ��{�^���������Ă��Ȃ�������
		{
			//0��1�͈ړ�  2��3�́A�ˌ��摜
			Player_Type++; //�v���C���[�摜�؂�ւ�
			if (Player_Type > 2)Player_Type = 0; //�v���C���[�摜0����X�^�[�g
			Image_time = 0; //�^�C�����Z�b�g
		}
		else //�ˌ�
		{
			//2��3�́A�ˌ��摜
			if (Player_Type == 3) //�ˌ��摜�Ȃ�
			{
				Player_Type = 2; //�v���C���[�摜2����
				Image_time = 0; //�^�C�����Z�b�g
			}
			else
			{
				Player_Type = 3; //�v���C���[�摜�ˌ��ɐ؂�ւ�
				Image_time = 0; //�^�C�����Z�b�g
			}

		}
	}

}

void  Player::Hit() //�U���������������̏����A���������̂��𔻒f����̂́ASphereCollider
{

}

int Player::LifeCheck()
{

	if (Life == -1) //���C�t��-1�Ȃ�TRUE��Ԃ�
	{
		return TRUE;
	}

	return FALSE;
}

int Player::GetScore()
{
	return 0; //�ۗ�
}

float Player::GetPlayerSpeed()
{
	return Player_Speed; //�v���C���[�̃X�s�[�h��Ԃ��B
}


bool Player::GetRight()
{
	return Right;
}

bool Player::GetLeft()
{
	return Left;
}

bool Player::GetShooting_Flag()
{
	return Shooting_Flag;
}