#pragma once
#include"CharaBase.h"

class player : public CharaBase
{
private:
	int score; //�X�R�A
	int life; //�c��c�@
	int player_images; //�v���C���[�C���[�W�摜
public:
	player();
	virtual AdstractScene* Update()override;
	virtual void Draw()const override; 
	//virtual void Hit()override;
	void LifeCheck();
	int GetScore();
};
