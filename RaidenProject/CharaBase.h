#pragma once

class CharaBase
{
private:
	//�|�C���^�z��
	//int* bullets[5];
	float Speed;
	int  Bullest_image; //�e�ےe
public:
	virtual void Update() = 0;
	virtual void Draw() const = 0;
	virtual void Hit() = 0;
};

