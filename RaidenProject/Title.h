#pragma once
#include"AdstractScene.h"

class Title :public AdstractScene
{
private:
	int Title_Images; //�^�C�g���摜
	int Title_BGM; //�^�C�g��BGM
	int Title_Drawingtime; //�����`�掞��

public:
	Title(); //�R���X�^���N�^
	virtual void Update() override; //�`��ȊO
	virtual void Draw() const override; //�`��̂�
	virtual AdstractScene* ChangeScene() override; //�V�[���؂�ւ�
};


