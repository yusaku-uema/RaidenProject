#pragma once

struct Bullets 
	{
		float x; //�e�ۍ��W
		float y; //�e�ۍ��W
		bool Bulletslost; //�e����ʂɂ��邩
	};
	
class BulletsBase
{
private:
	int Damage; //�^����_���[�W
	float Speed; //�e�̑��x
public:
	BulletsBase();
	virtual void Update() = 0;
	virtual void Draw()const = 0;
	int  GetDamage();
	float GetBulletsSpeed();
};

