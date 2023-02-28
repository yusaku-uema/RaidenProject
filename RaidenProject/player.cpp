#include"Player.h"
#include"DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>

#define NORMAL 3.5; //�v���C���[�̒ʏ�ړ��@

Player::Player()
{
	AX = 0;
	AY = 0;
	Image_time = 0;
	Score = 0;
	
	Life = 15;
	location.x = 310;
	location.y = 240;
	radius = 5;
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
		Playerbullers[i] = new PlayerBullers();
	}
}

Player::~Player()
{
	delete Playerbullers;
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
		if (Playerbullers[i]->GetReset() != true)
		{
			Playerbullers[i]->Draw();
		}
	}

}

void Player::Bullet()
{
	if (Shooting_Time++ % 20 == 0)//�e�۔��ˊԊu
	{
		if (BulletNum < 99)
		{
			BulletNum++;
		}
		else
		{
			BulletNum = 0;
		}


		if (Playerbullers[BulletNum]->GetReset() == true)
		{
			Playerbullers[BulletNum]->SetBullers(location.x, location.y - 18);
		}

	}

}

void  Player::ShootBullet() //�e�̓���
{
	for (int i = 0; i < 100; i++)
	{
		if (Playerbullers[i]->GetReset() != true)
		{
			Playerbullers[i]->Update();
		}
	}
}


void  Player::Operation() //�v���C���[����
{

	if (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_5) //LB�{�^�������������Ă��邩�B
	{
		Shooting_Flag = TRUE; //�ˌ��J�n
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
			location.x += Player_Speed;
			location.y -= Player_Speed;
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
			location.x -= Player_Speed;
			location.y += Player_Speed;
			Left = TRUE;
			Right = FALSE;
		}

		else if (AY > 0) //�X�e�b�N�����ɓ|��Ă�����
		{
			location.y += Player_Speed;
			Right = FALSE;
			Left = FALSE;
		}

		else if (AY < 0) //�X�e�b�N����ɓ|��Ă�����
		{
			location.y -= Player_Speed;
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

void  Player::Hit(int a) //�U���������������̏����A���������̂��𔻒f����̂́ASphereCollider
{
	Life -= a;
}

int Player::LifeCheck()
{

	if (Life <0) //���C�t��-1�Ȃ�TRUE��Ԃ�
	{
		return TRUE;
	}

	return FALSE;
}

void Player::Setlife(int a)
{
	if (Life + a > 20)
	{
		Life = 20;
	}
	else
	{
		Life += a;
	}
}

int Player::GetLife()
{
	return Life;
}

int Player::GetScore()
{
	return 0; //�ۗ�
}

float Player::GetPlayerSpeed()
{
	return Player_Speed; //�v���C���[�̃X�s�[�h��Ԃ��B
}

void Player::SetBullet(int i)
{
	Playerbullers[i]->SetReset(true);
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

bool Player::GetRest(int i)
{
	return Playerbullers[i]->GetReset();
}

PlayerBullers* Player::GetBullet(int i)const
{
	return Playerbullers[i];
}

bool Player::HitCheck(EnemyBullers* Enemybullers)
{

	bool ret = false; //�߂�l

	if (HitSphere(Enemybullers) == true)
	{
		ret = true;
	}
	return ret;
}

float Player::GetPlayer_X()
{
	return location.x;
}

float Player::GetPlayer_Y()
{
	return location.y;
}