#include"Player.h"
#include"DxLib.h"



Player::Player()
{
	Score = 0;
	Life = 0;
	Player_X = 0;
	Player_Y = 0;
	Player_Type = 0;
	LoadDivGraph("images/Player/Zerofighter plane.png", 4, 32, 1, 32, 32, Player_images);
	g_KeyFlg = 0;
	g_NowKey = 0;
	g_OldKey = 0;
	Shooting_Flag = FALSE;
}

void Player::Update()
{

	g_OldKey = g_NowKey;
	g_NowKey = GetJoypadInputState(DX_INPUT_PAD1); //�p�b�g���͎擾
	g_KeyFlg = g_NowKey & ~g_OldKey;

	GetJoypadAnalogInput(&AX, &AY, DX_INPUT_PAD1); //�X�e�b�N���͎擾

	Operation(AX, AY); //�v���C���[����
	ImageSwitching(AX, AY); //�v���C���[�摜�؂�ւ�

}

void Player::Draw() const
{

	DrawGraph(Player_X, Player_Y, Player_images[Player_Type], TRUE);
}

int Player::Operation(int AX, int AY) //�v���C���[����
{
	if (AX > 0) //�X�e�b�N���͂��E�ɓ|��Ă�����
	{
		Player_X++;
	}

	if (AX < 0) //�X�e�b�N���͂����ɓ|��Ă�����
	{
		Player_X--;
	}

}

int Player::ImageSwitching(int AX,int AY) //�v���C���[�摜�؂�ւ�
{
	if (AX > 0 || AX < 0 || AY > 0 || AY < 0) //�X�e�b�N���͂���Ă�����A�v���C���[�̉摜�؂�ւ�
	{
		if (++Image_time >= 5)
		{
			if (Shooting_Flag == FALSE) //�ˌ��{�^���������Ă��邩
			{
				//0��1�͈ړ�  2��4�́A�ˌ��摜
				Player_Type++; //�v���C���[�摜�؂�ւ�
				if (Player_Type > 2)Player_Type = 0; //�v���C���[�摜0����X�^�[�g
				Image_time = 0; //�^�C�����Z�b�g
			}
		}
	}
}



void Player::Hit()
{

}



//�K�v�Ȃ̂�������
//g_OldKey = g_NowKey;
//g_NowKey = GetJoypadInputState(DX_INPUT_PAD1);
//g_KeyFlg = g_NowKey & ~g_OldKey;
//
//GetJoypadAnalogInput(&AX, &AY, DX_INPUT_PAD1);
//
////if (g_KeyFlg & PAD_INPUT_LEFT) --Player_X; //��
////if (g_KeyFlg & PAD_INPUT_RIGHT) ++Player_X; //�E
////if (g_KeyFlg & PAD_INPUT_UP) --Player_Y; //��
////if (g_KeyFlg & PAD_INPUT_DOWN) ++Player_Y; //��
//
//Operation(AX, AY); //�v���C���[����
//ImageSwitching(AX, AY); //�v���C���[�摜�؂�ւ�
