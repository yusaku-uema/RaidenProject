#pragma once

#pragma once
#include"AdstractScene.h"

class GameMain : public AdstractScene 
{
private:
	//float player; //�|�C���^�ϐ�
	//int *enemy[5]; //�|�C���^�z��
public:
	//�f�X�g���N�^
	virtual ~GameMain() {};

	//�`��ȉ��̍X�V�����{����
	virtual AdstractScene* Update() override;

	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const override;

	void HitCheck(); //�����蔻��

};
