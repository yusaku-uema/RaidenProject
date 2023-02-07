#pragma once
#include"CharaBase.h"
#include"BulletsBase.h"
#include"SphereCollider.h"

class Player : public CharaBase , public BulletsBase 
{
private:

	//Key
	int g_KeyFlg;  
	int g_OldKey; //古いkey
	int g_NowKey; //現在のKey
	int AX, AY; //コントローラのステック入力
	bool Shooting_Flag; //射撃ボタンを押しているかいないのか
	bool Right; //右を向いているか
	bool Left;//左を向いているか

	//自機
	int Score; //スコア
	int Life; //残り残機
	bool Invincible_Flag; //ボムを使っている間無敵状態、今無敵状態なのかを確認するフラグ
	int Player_images[4]; //プレイヤーイメージ画像
	int Player_Type; //プレイヤー画像番号
	int Image_time; //プレイヤー画像切り替え
	float Player_Speed; //速度
	float Player_X; //プレイヤーX座標
	float Player_Y; //プレイヤーY座標
	//プレイヤーの弾丸
	int Shooting_Time; //ボタンを押している時の時間
	int Bullet_num; //弾丸の数
	int DrawBullet; 

	struct Bullets PlayerBullets[100]; //プレイヤーの弾丸の情報

public:

	//メンバ変数読み取り　http://www.s-cradle.com/developer/sophiaframework/tutorial/Cpp/access.html
	//インターネットにあったやり方.
	Player(); //コンストラクタ
	virtual void Update()override; //描画処理以外
	virtual void Draw()const override; //描画
	virtual void  Hit()override;
	void Bullet(); //プレイヤーの弾丸処理
	void ShootBullet(); //発射中の弾丸処理
	int LifeCheck(); //プレイヤー残機
	int GetScore(); //スコア
	void Operation(); //プレイヤー操作
	void ImageSwitching(); //画像切り替え
	float GetPlayerSpeed(); //プレイヤーのスピードを返す
	float GetPlayer_X(); //プレイヤー座標
	float GetPlayer_Y(); //プレイヤー座標
	bool GetRight(); //右を向いているか
	bool GetLeft();//左を向いているか
	bool GetShooting_Flag(); //射撃しているのか
};
