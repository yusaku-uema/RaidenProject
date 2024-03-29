#pragma once
#include"CharaBase.h"
#include"BulletsBase.h"
#include"Player.h"
#define EnemyMax 5 //敵の数最大


class Enemy :public CharaBase
{
private:
	int HP; //敵HP
	int Interval; //発射間隔
	int Bullers_num; //弾丸数
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
	void Hit(int a);
	void CreateEnemy(); //敵生成
	void AliveEnemy(); //敵が生きているのか（画面外、HPがなくなった）
	bool HPCheck();
	float Enemy_Y();
	int Getnum();
	bool HitCheck(PlayerBullers* playerbullers); //攻撃を受けたのか
	EnemyBullers* GetBullet(int i)const;

};
