#pragma once
#include"CharaBase.h"
#include"BulletsBase.h"
#include"PlayerBullers.h"

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
	//�v���C���[�̒e��
	int Shooting_Time; //�{�^���������Ă��鎞�̎���
	int BulletNum;
	int DrawBullet; 


public:

	//�����o�ϐ��ǂݎ��@http://www.s-cradle.com/developer/sophiaframework/tutorial/Cpp/access.html
	//�C���^�[�l�b�g�ɂ���������.
	Player(); //�R���X�g���N�^
	~Player();
	virtual void Update()override; //�`�揈���ȊO
	virtual void Draw()const override; //�`��
	virtual void  Hit(int a)override;
	void Bullet(); //�v���C���[�̒e�ۏ���
	void ShootBullet(); //���˒��̒e�ۏ���
	int LifeCheck(); //�v���C���[�c�@
	int GetScore(); //�X�R�A
	void Operation(); //�v���C���[����
	void ImageSwitching(); //�摜�؂�ւ�
	float GetPlayerSpeed(); //�v���C���[�̃X�s�[�h��Ԃ�
	float GetPlayer_X();
	float GetPlayer_Y();
	void SetBullet(int i);
	bool GetRight(); //�E�������Ă��邩
	bool GetLeft();//���������Ă��邩
	bool GetShooting_Flag(); //�ˌ����Ă���̂�
	bool GetRest(int i);
	PlayerBullers* GetBullet(int i)const;
	
};
