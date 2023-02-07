#include"Player.h"
#include"DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>

#define NORMAL 2.2; //プレイヤーの通常移動
#define ATTACK 2.2; //攻撃状態の移動速度　　（遅くするか、もしくはそのままか迷っている）

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
		SetBullets_flg(i, true); //画面外もしくは、存在にしてない。
		SetBullets_X(i, 0);
		SetBullets_Y(i, 0);
	}

}

void Player::Update()
{

	g_OldKey = g_NowKey;
	g_NowKey = GetJoypadInputState(DX_INPUT_PAD1); //パット入力取得
	g_KeyFlg = g_NowKey & ~g_OldKey;

	GetJoypadAnalogInput(&AX, &AY, DX_INPUT_PAD1); //ステック入力取得
    ShootBullet();
	Operation(); //プレイヤー操作
	ImageSwitching(); //プレイヤー画像切り替え
	
}

void Player::Draw() const
{

	if (g_KeyFlg & PAD_INPUT_4) //RBボタンを押し続けているか。
	{
		DrawFormatString(320, 240, 0xFFFFFF, "yusaku");
	}

	if (Left == TRUE) //左に傾いている画像
	{
		DrawRotaGraph(Player_X, Player_Y, 1.5f, (M_PI / 180) * -45, Player_images[Player_Type], TRUE); //画像、左に傾け
	}
	else if (Right == TRUE) //右に傾いている画像
	{
		DrawRotaGraph(Player_X, Player_Y, 1.5f, (M_PI / 180) * 45, Player_images[Player_Type], TRUE); //画像、右に傾け
	}

	else
	{
		DrawRotaGraph(Player_X, Player_Y, 1.5f, 0, Player_images[Player_Type], TRUE); //画像真っ直ぐ
	}

	for (int i = 0; i < 100; i++)
	{
		if(GetBullets_flg(i) == false)DrawCircle(GetBullets_X(i), GetBullets_Y(i), 5, GetColor(255, 0, 255), TRUE);//弾描画
	}
}

void Player::Bullet()
{
	if (Shooting_Time++ % 10 == 0)//弾丸発射間隔
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


void  Player::Operation() //プレイヤー操作
{

	if (g_KeyFlg && PAD_INPUT_4) //RBボタンを押し続けているか。
	{
		Invincible_Flag = TRUE;
		DrawFormatString(320, 240, 0xFFFFFF, "ボム");
	}

	if (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_5) //LBボタンを押し続けているか。
	{
		Shooting_Flag = TRUE; //射撃開始
		Player_Speed = ATTACK; //移動速度低下
		Bullet();
	}
	else
	{
		Shooting_Flag = FALSE; //通常状態
		Player_Speed = NORMAL; //巡航速度に戻す
	}
	if (Player_X < 640 - 32 && Player_Y < 480 - 32 && Player_X > 32 && Player_Y > 32)
	{
		if (AX > 0 && AY > 0) //ステックが右&下に倒れていたら
		{
			Player_X = Player_X + Player_Speed;
			Player_Y = Player_Y + Player_Speed;
			Right = TRUE;
			Left = FALSE;
		}

		else if (AX > 0 && AY < 0) //ステックが右&上に倒れていたら
		{
			Player_X = Player_X + Player_Speed;
			Player_Y = Player_Y - Player_Speed;
			Right = TRUE;
			Left = FALSE;
		}

		else if (AX < 0 && AY < 0) //ステックが左&上に倒れていたら
		{
			Player_X = Player_X - Player_Speed;
			Player_Y = Player_Y - Player_Speed;
			Left = TRUE;
			Right = FALSE;
		}

		else if (AX < 0 && AY > 0) //ステックが左&下に倒れていたら
		{
			Player_X = Player_X - Player_Speed;
			Player_Y = Player_Y + Player_Speed;
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

		else if (AX > 0) //ステックが右に倒れていたら
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

void  Player::Hit() //攻撃が当たった時の処理、当たったのかを判断するのは、SphereCollider
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

int Player::GetScore()
{
	return 0; //保留
}

float Player::GetPlayerSpeed()
{
	return Player_Speed; //プレイヤーのスピードを返す。
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