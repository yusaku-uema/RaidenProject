#pragma once
#include"AdstractScene.h"

class Title :public AdstractScene
{
private:
	int Title_images; //�^�C�g���摜
	int Title_bgm; //�^�C�g��BGM
	int Title_Drawingtime; //�����`�掞��
public:
 	Title ();
	virtual AdstractScene* Update() override;
	void Draw() const override;
	void test(); //�e�X�g���̃N���X�Ƃ̊֐��Ăт���
};


