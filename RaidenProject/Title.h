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
	virtual void Update() override;
	virtual void Draw() const override;
	virtual AdstractScene* ChangeScene() override;
};


