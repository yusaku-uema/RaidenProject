#pragma once
#include"AdstractScene.h"
#include"Player.h"

class GameMain : public AdstractScene 
{
private:
	Player *player;
public:
	
	GameMain();

	//�`��ȉ��̍X�V�����{����
	void Update() override;

	//�`��Ɋւ��邱�Ƃ���������
	void Draw() const override;
	AdstractScene* ChangeScene() override;

	void HitCheck(); //�����蔻��


};
