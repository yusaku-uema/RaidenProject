#include"Player.h"
#include"DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>

#define NORMAL 1.5;
#define ATTACK 0.5;

Player::Player()
{
	AX = 0;
	AY = 0;
	Image_time = 0;
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
	Player_Speed = NORMAL;
	Right = FALSE;
	Left = FALSE;
}

void Player::Update()
{

	g_OldKey = g_NowKey;
	g_NowKey = GetJoypadInputState(DX_INPUT_PAD1); //パット入力取得
	g_KeyFlg = g_NowKey & ~g_OldKey;

	GetJoypadAnalogInput(&AX, &AY, DX_INPUT_PAD1); //ステック入力取得

	Operation(); //プレイヤー操作
	ImageSwitching(); //プレイヤー画像切り替え

}

void Player::Draw() const
{
	if (Left == TRUE) //左
	{
		DrawRotaGraph(Player_X, Player_Y, 1.5f, M_PI / 2, Player_images[Player_Type], TRUE);
		//DrawRotaGraph( 320 , 240 , 1.5f , PI / 2 , GHandle , TRUE ) ;
	}
	else if (Right == TRUE)
	{
		DrawRotaGraph(Player_X, Player_Y, 1.5f, M_PI, Player_images[Player_Type], TRUE);
	}
	
	else
	{
		DrawRotaGraph(Player_X, Player_Y, 1.5f, 0, Player_images[Player_Type], TRUE);
	}
}

void  Player::Operation() //プレイヤー操作
{

	if (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_5) //LBボタンを押し続けているか。
	{
		Shooting_Flag = TRUE; //射撃開始
		Player_Speed = ATTACK; //移動速度低下
	}
	else
	{
		Shooting_Flag = FALSE; //通常状態
		Player_Speed = NORMAL; //巡航速度に戻す
	}

	if (AX > 0) //ステックが右に倒れていたら
	{
		Player_X = Player_X + Player_Speed;
		Right = TRUE;
		Left = FALSE;
	}

	else if (AX < 0) //ステックが左に倒れていたら
	{
		Player_X = Player_X - Player_Speed;
		Left = TRUE;
		Right = FALSE;
	}

	else if (AY > 0) //ステックが下に倒れていたら
	{
		Player_Y = Player_Y + Player_Speed;
		Right = FALSE;
		Left = FALSE;
	}

	else if (AY < 0) //ステックが上に倒れていたら
	{
		Player_Y = Player_Y - Player_Speed;
		Right = FALSE;
		Left = FALSE;
	}
	else
	{
		Right = FALSE;
		Left = FALSE;
	}
}

void  Player::ImageSwitching() //プレイヤー画像切り替え
{
	if (++Image_time >= 5)
	{
		if (Shooting_Flag == FALSE) //射撃ボタンを押していなかったら
		{
			//0と1は移動  2と3は、射撃画像
			Player_Type++; //プレイヤー画像切り替え
			if (Player_Type > 2)Player_Type = 0; //プレイヤー画像0からスタート
			Image_time = 0; //タイムリセット
		}
		else //射撃
		{
			//2と3は、射撃画像
			if (Player_Type == 3) //射撃画像なら
			{
				Player_Type = 2; //プレイヤー画像2する
				Image_time = 0; //タイムリセット
			}
			else
			{
				Player_Type = 3; //プレイヤー画像射撃に切り替え
				Image_time = 0; //タイムリセット
			}

		}
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
