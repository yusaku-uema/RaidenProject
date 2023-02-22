#pragma once
#include"CharaBase.h"
#include"BulletsBase.h"
#include"SphereCollider.h"
#include"Player.h"
#define EnemyMax 6 //敵の数最大


class Enemy :public CharaBase,public SphereCollider
{
private:
	float x; //敵座標
	float y; //敵座標
	int HP; //敵HP
	int Point; //敵を倒した時のポイント
	int EnemyTyper; //敵の種類
	int EnemyTime; //敵の出現間隔
	int Bomber_Images; //爆撃機
	bool Enemylost; //敵が出現しているか
	bool EnemyHit; //攻撃を食らったか。
	

public:
	Enemy(); //コンストラクタ
	void Update()override;
	void Draw()const override;
	void Hit()override;
	void CreateEnemy(); //敵生成
	void AliveEnemy(); //敵が生きているのか（画面外、HPがなくなった）
	void HPCheck();
	void GetPoint();
	bool HitCheck(Player* player); //攻撃を受けたのか
};

