#include"Player.h"
#include"DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>

#define NORMAL 2;
#define ATTACK 1;

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
		DrawRotaGraph(Player_X, Player_Y, 1.5f,(M_PI / 180 )* -45, Player_images[Player_Type], TRUE); //画像、左に傾け
	}
	else if (Right == TRUE)
	{
		DrawRotaGraph(Player_X, Player_Y, 1.5f,( M_PI/180) * 45, Player_images[Player_Type], TRUE); //画像、右に傾け
	}
	
	else
	{
		DrawRotaGraph(Player_X, Player_Y, 1.5f, 0, Player_images[Player_Type], TRUE); //画像真っ直ぐ
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
	if (Player_X < 640 - 32 && Player_Y < 480 - 32 && Player_X > 32 && Player_Y > 32)
	{
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
		else //何も操作していない。
		{
			Right = FALSE;
			Left = FALSE;
		}
	}

	if (Player_X <= 32) //画面外に行ったら座標を戻す
	{
		Player_X = 34;
	}

	if (Player_X >= 608) //画面外に行ったら座標を戻す
	{
		Player_X = 606;
	}

	if (Player_Y >= 448) //画面外に行ったら座標を戻す。
	{
		Player_Y = 446;
	}

	if (Player_Y <= 32)//画面外に行ったら座標を戻す。
	{
		Player_Y = 34;
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

void Player::Hit() //攻撃が当たったのか
{

}

int Player::LifeCheck()
{

	if (Life == -1) //ライフが-1ならTRUEを返す
	{
		return TRUE;
	}

	return FALSE;
}
