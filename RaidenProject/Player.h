#pragma once
#include"CharaBase.h"

class Player : public CharaBase
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
	int Player_images[4]; //プレイヤーイメージ画像
	int Player_Type; //プレイヤー画像番号
	int Image_time; //プレイヤー画像切り替え
	int Player_Speed; //速度
	int Player_X; //プレイヤーX座標
	int Player_Y; //プレイヤーY座標


public:
	Player(); //コンストラクタ
	virtual void Update()override; //描画処理以外
	virtual void Draw()const override; //描画
	virtual void Hit()override;
	int LifeCheck();
	int GetScore();
	void Operation(); //プレイヤー操作
	void ImageSwitching(); //画像切り替え
	
};
