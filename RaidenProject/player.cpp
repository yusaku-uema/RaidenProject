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
}

void Player::Update()
{

	g_OldKey = g_NowKey;
	g_NowKey = GetJoypadInputState(DX_INPUT_PAD1); //パット入力取得
	g_KeyFlg = g_NowKey & ~g_OldKey;

	GetJoypadAnalogInput(&AX, &AY, DX_INPUT_PAD1); //ステック入力取得

	Operation(AX, AY); //プレイヤー操作
	ImageSwitching(AX, AY); //プレイヤー画像切り替え

}

void Player::Draw() const
{

	DrawGraph(Player_X, Player_Y, Player_images[Player_Type], TRUE);
}

int Player::ImageSwitching(int AX,int AY) //プレイヤー画像切り替え
{
	if (AX > 0 || AX < 0 || AY > 0 || AY < 0) //ステック入力されていたら、プレイヤーの画像切り替え
	{
		if (++Image_time >= 5)
		{
			Player_Type++; //プレイヤー画像切り替え
			if (Player_Type > 3)Player_Type = 0; //プレイヤー画像0からスタート
			Image_time = 0; //タイムリセット
		}
	}
}

int Player::Operation(int AX, int AY)
{
	if (AX > 0) //ステック入力が右に倒れていたら
	{
		Player_X++;
	}

	if (AX < 0) //ステック入力が左に倒れていたら
	{
		Player_X--;
	}

}

void Player::Hit()
{

}



//必要なのか検討中
//g_OldKey = g_NowKey;
//g_NowKey = GetJoypadInputState(DX_INPUT_PAD1);
//g_KeyFlg = g_NowKey & ~g_OldKey;
//
//GetJoypadAnalogInput(&AX, &AY, DX_INPUT_PAD1);
//
////if (g_KeyFlg & PAD_INPUT_LEFT) --Player_X; //左
////if (g_KeyFlg & PAD_INPUT_RIGHT) ++Player_X; //右
////if (g_KeyFlg & PAD_INPUT_UP) --Player_Y; //上
////if (g_KeyFlg & PAD_INPUT_DOWN) ++Player_Y; //下
//
//Operation(AX, AY); //プレイヤー操作
//ImageSwitching(AX, AY); //プレイヤー画像切り替え
