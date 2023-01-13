#pragma once
#include "CharaBase.h"
#include"BulletsBase.h"
#define EnemyMax 15 //敵の数最大

class Enemy :public CharaBase,public BulletsBase
{
private:
	int EnemyTime; //敵の出現間隔
	int Bomber_Images; //爆撃機
	int Heri_Images[3]; //ヘリコプター
	int EnemyBoss_Images; //ボス画像
	int Jetfighter_Images; //ジェット戦闘機
	int MesserschmittMe262; //メッサーシュミット画像
	int Enemynum; //現在の敵の数

	struct Enemyinformation
	{
		float x; //座標
		float y; //座標
		int HP; //敵HP
		int Point; //敵を倒した時のポイント
		int EnemyTyper; //敵の種類
		bool Enemylost; //敵が出現しているか
	};
	struct Enemyinformation EnemyNumber[EnemyMax];

public:
	Enemy(); //コンストラクタ
	void Update()override;
	void Draw()const override;
	void Hit()override;
	void HpCheck();
	void GetPoint();
};

