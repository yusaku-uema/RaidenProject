#pragma once
#include "AdstractScene.h"
class Result :public AdstractScene
{
private:
	int Result_Drawingtime; //�����`�掞��
	int Enemy_num; //�|�����G

public:
	Result(int a); //�R���X�^���N�^
	virtual void Update() override; //�`��ȊO
	virtual void Draw() const override; //�`��̂�
	virtual AdstractScene* ChangeScene() override; //�V�[���؂�ւ�
};

