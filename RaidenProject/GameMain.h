#pragma once
#include"AdstractScene.h"
#include"Title.h" //�e�X�g

class GameMain : public AdstractScene 
{
private:
	float *player; //�|�C���^�ϐ�
	int *enemy[5]; //�|�C���^�z��
public:
	Title* test;
	GameMain();

	//�`��ȉ��̍X�V�����{����
	virtual AdstractScene* Update() override;

	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const override;

	void HitCheck(); //�����蔻��


};
