#pragma once
#include"AdstractScene.h"
#include"Player.h"

class GameMain : public AdstractScene 
{
private:
//�C���^�[�l�b�g�ɂ��������̃N���X�̎Q��,https://cpp-lang.sevendays-study.com/ex-day2.html
	Player *player; 
public:
	//�R���X�g���N�^
	GameMain();

	//�`��ȉ��̍X�V�����{����
	void Update() override;

	//�`��Ɋւ��邱�Ƃ���������
	void Draw() const override;

	//�V�[���؂�ւ�
	AdstractScene* ChangeScene() override;

	//�����蔻��
	void HitCheck(); 


};
