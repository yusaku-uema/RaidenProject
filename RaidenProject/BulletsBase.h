#pragma once
class BulletsBase
{
private:
	int Damage; //�^����_���[�W
	float Speed; //�e�̑��x

	struct Bullets
	{
		float x; //�e�ۍ��W
		float y; //�e�ۍ��W
		bool Bulletslost; //�e����ʂɂ��邩
	};
	struct Bullets PlayerBullets[100];
	struct Bullets EnemyBullets[100];
	

public:
	BulletsBase();
	virtual void Update() = 0;
	virtual void Draw()const = 0;
	int  GetDamage();
	float GetBulletsSpeed();
};

