#pragma once
#include"CharaBase.h"
#include"BulletsBase.h"
#include"SphereCollider.h"
#define EnemyMax 6 //“G‚Ì”Å‘å


class Enemy :public CharaBase,public SphereCollider
{
private:
	float x; //“GÀ•W
	float y; //“GÀ•W
	int HP; //“GHP
	int Point; //“G‚ğ“|‚µ‚½‚Ìƒ|ƒCƒ“ƒg
	int EnemyTyper; //“G‚Ìí—Ş
	int EnemyTime; //“G‚ÌoŒ»ŠÔŠu
	int Bomber_Images; //”šŒ‚‹@
	bool Enemylost; //“G‚ªoŒ»‚µ‚Ä‚¢‚é‚©
	

public:
	Enemy(); //ƒRƒ“ƒXƒgƒ‰ƒNƒ^
	void Update()override;
	void Draw()const override;
	void Hit()override;
	void CreateEnemy(); //“G¶¬
	void AliveEnemy(); //“G‚ª¶‚«‚Ä‚¢‚é‚Ì‚©i‰æ–ÊŠOAHP‚ª‚È‚­‚È‚Á‚½j
	void HPCheck();
	void GetPoint();
};

