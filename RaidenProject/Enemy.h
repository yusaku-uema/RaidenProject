#pragma once
#include"CharaBase.h"
#include"BulletsBase.h"
#include"Player.h"
#define EnemyMax 8 //“G‚Ì”Å‘å


class Enemy :public CharaBase
{
private:
	int HP; //“GHP
	int Interval; //”­ËŠÔŠu
	int Bullers_num; //’eŠÛ”
	int Point; //“G‚ğ“|‚µ‚½‚Ìƒ|ƒCƒ“ƒg
	int EnemyTyper; //“G‚Ìí—Ş
	int EnemyTime; //“G‚ÌoŒ»ŠÔŠu
	int Bomber_Images; //”šŒ‚‹@
	bool Enemylost; //“G‚ªoŒ»‚µ‚Ä‚¢‚é‚©
	bool EnemyHit; //UŒ‚‚ğH‚ç‚Á‚½‚©B


public:
	Enemy(); //ƒRƒ“ƒXƒgƒ‰ƒNƒ^
	void Update()override;
	void Draw()const override;
	void Hit(int a);
	void CreateEnemy(); //“G¶¬
	void Bullers();
	void AliveEnemy(); //“G‚ª¶‚«‚Ä‚¢‚é‚Ì‚©i‰æ–ÊŠOAHP‚ª‚È‚­‚È‚Á‚½j
	void HPCheck();
	void GetPoint();
	float Enemy_Y();
	int Getnum();
	bool HitCheck(PlayerBullers* playerbullers); //UŒ‚‚ğó‚¯‚½‚Ì‚©
	EnemyBullers* GetBullet(int i)const;

};
