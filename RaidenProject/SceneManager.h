#pragma once
#include"AdstractScene.h"

//�V�[���}�l�[�W���[�N���X
//�e�V�[���̐؂�ւ����Ǘ�����B
class SceneManager : public AdstractScene {
private:
	AdstractScene* mScene; //���݂̃V�[��

public:
	//�R���X�g���N�^
	SceneManager(AdstractScene* scene) :mScene(scene) {}

	//�f�X�g���N�^
	~SceneManager() {
		delete mScene;
	}

	//�`��ȊO�̍X�V����������
	AdstractScene* Update() override;

	//�`��Ɋւ��邱�Ƃ���������
	void Draw() const override;
};