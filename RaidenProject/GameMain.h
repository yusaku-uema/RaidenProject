#pragma once
#include"AdstractScene.h"
#include"Player.h"

class GameMain : public AdstractScene 
{
private:
	player* player;

public:
	
	GameMain();

	//�`��ȉ��̍X�V�����{����
	virtual AdstractScene* Update() override;

	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const override;

	void HitCheck(); //�����蔻��


};
