#pragma once
#include"CharaBase.h"
#include"BulletsBase.h"

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
	bool Invincible_Flag; //�{�����g���Ă���Ԗ��G��ԁA�����G��ԂȂ̂����m�F����t���O
	int Player_images[4]; //�v���C���[�C���[�W�摜
	int Player_Type; //�v���C���[�摜�ԍ�
	int Image_time; //�v���C���[�摜�؂�ւ�
	float Player_Speed; //���x
	float Player_X; //�v���C���[X���W
	float Player_Y; //�v���C���[Y���W


public:

	//�����o�ϐ��ǂݎ��@http://www.s-cradle.com/developer/sophiaframework/tutorial/Cpp/access.html
	// Player(CharaBase charabase); �C���^�[�l�b�g�ɂ����������A�����o�ϐ��������ŎQ�ƁH
	Player(); //�R���X�g���N�^
	virtual void Update()override; //�`�揈���ȊO
	virtual void Draw()const override; //�`��
	virtual void Hit()override;
	int LifeCheck();
	int GetScore(); 
	void Operation(); //�v���C���[����
	void ImageSwitching(); //�摜�؂�ւ�
	float GetPlayerSpeed(); //�v���C���[�̃X�s�[�h��Ԃ�
};
