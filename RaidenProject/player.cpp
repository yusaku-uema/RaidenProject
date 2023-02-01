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
	Player_X = 310;
	Player_Y = 240;
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
	Bullet_num = 0;
	DrawBullet = 0;

	for (int i = 0; i < 100; i++)
	{
		SetBullets_flg(i, true); //��ʊO�������́A���݂ɂ��ĂȂ��B
		SetBullets_X(i, 0);
		SetBullets_Y(i, 0);
	}

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
		DrawRotaGraph(Player_X, Player_Y, 1.5f, (M_PI / 180) * -45, Player_images[Player_Type], TRUE); //�摜�A���ɌX��
	}
	else if (Right == TRUE) //�E�ɌX���Ă���摜
	{
		DrawRotaGraph(Player_X, Player_Y, 1.5f, (M_PI / 180) * 45, Player_images[Player_Type], TRUE); //�摜�A�E�ɌX��
	}

	else
	{
		DrawRotaGraph(Player_X, Player_Y, 1.5f, 0, Player_images[Player_Type], TRUE); //�摜�^������
	}

	for (int i = 0; i < 100; i++)
	{
		if(GetBullets_flg(i) == false)DrawCircle(GetBullets_X(i), GetBullets_Y(i), 5, GetColor(255, 0, 255), TRUE);//�e�`��
	}
}

void Player::Bullet()
{
	if (Shooting_Time++ % 10 == 0)//�e�۔��ˊԊu
	{
		bool a = TRUE; //
		for (int i = 0; i < 100; i++)
		{
			if (Shooting_Flag == TRUE) {
				if (GetBullets_flg(i) == true && a == TRUE)
				{
					SetBullets_flg(i, false);
					SetBullets_X(i, Player_X);
					SetBullets_Y(i, Player_Y - 18);
					a = FALSE;
				}
			}
		}
		
	}

}

void  Player::ShootBullet()
{
	for (int i = 0; i < 100; i++)
	{
		if (GetBullets_flg(i) == false)
		{
			SetBullets_Y(i, GetBullets_Y(i) - 3.5);
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
	if (Player_X < 640 - 32 && Player_Y < 480 - 32 && Player_X > 32 && Player_Y > 32)
	{
		if (AX > 0 && AY > 0) //�X�e�b�N���E&���ɓ|��Ă�����
		{
			Player_X = Player_X + Player_Speed;
			Player_Y = Player_Y + Player_Speed;
			Right = TRUE;
			Left = FALSE;
		}

		else if (AX > 0 && AY < 0) //�X�e�b�N���E&��ɓ|��Ă�����
		{
			Player_X = Player_X + Player_Speed;
			Player_Y = Player_Y - Player_Speed;
			Right = TRUE;
			Left = FALSE;
		}

		else if (AX < 0 && AY < 0) //�X�e�b�N����&��ɓ|��Ă�����
		{
			Player_X = Player_X - Player_Speed;
			Player_Y = Player_Y - Player_Speed;
			Left = TRUE;
			Right = FALSE;
		}

		else if (AX < 0 && AY > 0) //�X�e�b�N����&���ɓ|��Ă�����
		{
			Player_X = Player_X - Player_Speed;
			Player_Y = Player_Y + Player_Speed;
			Left = TRUE;
			Right = FALSE;
		}

		else if (AY > 0) //�X�e�b�N�����ɓ|��Ă�����
		{
			Player_Y = Player_Y + Player_Speed;
			Right = FALSE;
			Left = FALSE;
		}

		else if (AY < 0) //�X�e�b�N����ɓ|��Ă�����
		{
			Player_Y = Player_Y - Player_Speed;
			Right = FALSE;
			Left = FALSE;
		}

		else if (AX > 0) //�X�e�b�N���E�ɓ|��Ă�����
		{
			Player_X = Player_X + Player_Speed;
			Right = TRUE;
			Left = FALSE;
		}

		else if (AX < 0) //�X�e�b�N�����ɓ|��Ă�����
		{
			Player_X = Player_X - Player_Speed;
			Left = TRUE;
			Right = FALSE;
		}

		else //�������삵�Ă��Ȃ��B
		{
			Right = FALSE;
			Left = FALSE;
		}
	}

	if (Player_X <= 32) //��ʊO�ɍs��������W��߂�
	{
		Player_X = 34;
	}

	if (Player_X >= 608) //��ʊO�ɍs��������W��߂�
	{
		Player_X = 606;
	}

	if (Player_Y >= 448) //��ʊO�ɍs��������W��߂��B
	{
		Player_Y = 446;
	}

	if (Player_Y <= 32)//��ʊO�ɍs��������W��߂��B
	{
		Player_Y = 34;
	}

	for (int i = 0; i < 100; i++)
	{
		if (GetBullets_flg(i) == false) {
			if (GetBullets_X(i) < 0 || GetBullets_X(i) > 620 || GetBullets_Y(i) > 480 || GetBullets_Y(i) < -10)
			{
				SetBullets_flg(i, true);
				SetBullets_X(i, 0);
				SetBullets_Y(i, 0);
			}
		}
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

void  Player::Hit() //�U�������������̂�
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

float Player::GetPlayer_X()
{
	return Player_X;
}

float Player::GetPlayer_Y()
{
	return Player_Y;
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