#include"Player.h"
#include"DxLib.h"



Player::Player()
{
	Score = 0;
	Life = 0;
	Player_X = 0;
	Player_Y = 0;
	imagesnum = 0;
	LoadDivGraph("images/Player/Zerofighter plane.png", 4, 32, 1, 32, 32, Player_images);
	g_KeyFlg = 0;
	g_NowKey = 0;
	g_OldKey = 0;
}

void Player::Update()
{

	g_OldKey = g_NowKey;
	g_NowKey = GetJoypadInputState(DX_INPUT_PAD1);
	g_KeyFlg = g_NowKey & ~g_OldKey;

	if (g_KeyFlg & PAD_INPUT_LEFT) --Player_X; //��
	if (g_KeyFlg & PAD_INPUT_RIGHT) ++Player_X; //�E
	if (g_KeyFlg & PAD_INPUT_UP) --Player_Y; //��
	if (g_KeyFlg & PAD_INPUT_DOWN) ++Player_Y; //��
}

void Player::Draw() const
{

	DrawGraph(Player_X, Player_Y, Player_images[imagesnum], TRUE);
}

void Player::Hit()
{

}

