#pragma once
#include"AdstractScene.h"
#include"Player.h"
#include"PlayerBullers.h"
#include"Enemy.h"
#include"BulletsBase.h"
#include"Recovery.h"

#define PLAYER_BULLETS 100 //�v���C���[�̒e�ۂ̐�

class GameMain : public AdstractScene
{
private:
	//�C���^�[�l�b�g�ɂ��������̃N���X�̎Q��,https://cpp-lang.sevendays-study.com/ex-day2.html
	Player* player;
	Enemy* enemy[EnemyMax];
	Recovery* recovery;
	int Stage_Images; //�X�e�[�W�摜
	int Mileage; //���s����
	int BullersNum; //�e�ۂ̐�
	int BullersTime; //���Ԃ��o�߂��邲�Ƃɒe�ې���������B
	int Enemy_num; //�|�����G

public:

	//�R���X�g���N�^
	GameMain();

	//�f�X�g���N�^
	~GameMain();

	//�`��ȉ��̍X�V�����{����
	void Update() override;

	//�`��Ɋւ��邱�Ƃ���������
	void Draw() const override;

	//�V�[���؂�ւ�
	AdstractScene* ChangeScene() override;

	//�����蔻��
	void HitCheck();

};
