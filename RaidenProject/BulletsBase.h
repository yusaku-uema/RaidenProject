#pragma once
class BulletsBase
{
private:
	int Damage; //�^����_���[�W
	float Speed; //�e�̑��x

	struct PlayerBullets
	{
		float x;
		float y;

	};

public:
	BulletsBase();
	virtual void Update() = 0;
	virtual void Draw()const = 0;
	int  GetDamage();
	float GetBulletsSpeed();
};

