#pragma once
#include"AdstractScene.h"

class GameMain : public AdstractScene 
{
private:
public:
	
	GameMain();

	//�`��ȉ��̍X�V�����{����
	virtual void Update() override;

	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const override;
	virtual AdstractScene* ChangeScene() override;

	void HitCheck(); //�����蔻��


};
