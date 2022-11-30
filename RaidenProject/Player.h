#pragma once
#include"CharaBase.h"

class Player : public CharaBase
{
private:

	//Key
	int g_KeyFlg; 
	int g_OldKey; //�Â�key
	int g_NowKey; //���݂�Key
	int AX, AY; //�R���g���[���̃X�e�b�N����
	bool Shooting_Flag; //�ˌ��{�^���������Ă��邩���Ȃ��̂�
	bool Right; //�E�������Ă��邩
	bool Left;//���������Ă��邩

	//���@
	int Score; //�X�R�A
	int Life; //�c��c�@
	int Player_images[4]; //�v���C���[�C���[�W�摜
	int Player_Type; //�v���C���[�摜�ԍ�
	int Image_time; //�v���C���[�摜�؂�ւ�
	float Player_Speed; //���x
	float Player_X; //�v���C���[X���W
	float Player_Y; //�v���C���[Y���W


public:
	Player(); //�R���X�g���N�^
	virtual void Update()override; //�`�揈���ȊO
	virtual void Draw()const override; //�`��
	virtual void Hit()override;
	void LifeCheck();
	int GetScore();
	void Operation(); //�v���C���[����
	void ImageSwitching(); //�摜�؂�ւ�
	
};
