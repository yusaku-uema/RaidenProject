#pragma once
class BulletsBase
{
private:
	int damage; //�^����_���[�W
	int speed; //�e�̑��x
public:
	BulletsBase();
	virtual void Update() = 0;
	virtual void Draw()const = 0;
	void GetDamage();
};

