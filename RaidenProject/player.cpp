#include"Player.h"
#include"DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>

#define NORMAL 3.5; //プレイヤーの通常移動　

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
	g_NowKey = GetJoypadInputState(DX_INPUT_PAD1); //パット入力取得
	g_KeyFlg = g_NowKey & ~g_OldKey;

	GetJoypadAnalogInput(&AX, &AY, DX_INPUT_PAD1); //ステック入力取得
	ShootBullet();
	Operation(); //プレイヤー操作
	ImageSwitching(); //プレイヤー画像切り替え

}

void Player::Draw() const
{
	if (Left == TRUE) //左に傾いている画像
	{
		DrawRotaGraph(location.x, location.y, 1.5f, (M_PI / 180) * -45, Player_images[Player_Type], TRUE); //画像、左に傾け
	}
	else if (Right == TRUE) //右に傾いている画像
	{
		DrawRotaGraph(location.x, location.y, 1.5f, (M_PI / 180) * 45, Player_images[Player_Type], TRUE); //画像、右に傾け
	}

	else
	{
		DrawRotaGraph(location.x, location.y, 1.5f, 0, Player_images[Player_Type], TRUE); //画像真っ直ぐ
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
	if (Shooting_Time++ % 20 == 0)//弾丸発射間隔
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

void  Player::ShootBullet() //弾の動き
{
	for (int i = 0; i < 100; i++)
	{
		if (Playerbullers[i]->GetReset() != true)
		{
			Playerbullers[i]->Update();
		}
	}
}


void  Player::Operation() //プレイヤー操作
{

	if (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_5) //LBボタンを押し続けているか。
	{
		Shooting_Flag = TRUE; //射撃開始
		Bullet();
	}
	else
	{
		Shooting_Flag = FALSE; //通常状態
		Player_Speed = NORMAL; //巡航速度に戻す
	}
	if (location.x < 640 - 32 && location.y < 480 - 32 && location.x > 32 && location.y > 32)
	{
		if (AX > 0 && AY > 0) //ステックが右&下に倒れていたら
		{
			location.x += Player_Speed;
			location.y += Player_Speed;
			Right = TRUE;
			Left = FALSE;
		}

		else if (AX > 0 && AY < 0) //ステックが右&上に倒れていたら
		{
			location.x += Player_Speed;
			location.y -= Player_Speed;
			Right = TRUE;
			Left = FALSE;
		}

		else if (AX < 0 && AY < 0) //ステックが左&上に倒れていたら
		{
			location.x -= Player_Speed;
			location.y -= Player_Speed;
			Left = TRUE;
			Right = FALSE;
		}

		else if (AX < 0 && AY > 0) //ステックが左&下に倒れていたら
		{
			location.x -= Player_Speed;
			location.y += Player_Speed;
			Left = TRUE;
			Right = FALSE;
		}

		else if (AY > 0) //ステックが下に倒れていたら
		{
			location.y += Player_Speed;
			Right = FALSE;
			Left = FALSE;
		}

		else if (AY < 0) //ステックが上に倒れていたら
		{
			location.y -= Player_Speed;
			Right = FALSE;
			Left = FALSE;
		}

		else if (AX > 0) //ステックが右に倒れていたら
		{
			location.x += Player_Speed;
			Right = TRUE;
			Left = FALSE;
		}

		else if (AX < 0) //ステックが左に倒れていたら
		{
			location.x -= Player_Speed;
			Left = TRUE;
			Right = FALSE;
		}

		else //何も操作していない。
		{
			Right = FALSE;
			Left = FALSE;
		}
	}

	if (location.x <= 32) //画面外に行ったら座標を戻す
	{
		location.x = 34;
	}

	if (location.x >= 608) //画面外に行ったら座標を戻す
	{
		location.x = 606;
	}

	if (location.y >= 448) //画面外に行ったら座標を戻す。
	{
		location.y = 446;
	}

	if (location.y <= 32)//画面外に行ったら座標を戻す。
	{
		location.y = 34;
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

void  Player::Hit(int a) //攻撃が当たった時の処理、当たったのかを判断するのは、SphereCollider
{
	Life -= a;
}

int Player::LifeCheck()
{

	if (Life <0) //ライフが-1ならTRUEを返す
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
	return 0; //保留
}

float Player::GetPlayerSpeed()
{
	return Player_Speed; //プレイヤーのスピードを返す。
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

	bool ret = false; //戻り値

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