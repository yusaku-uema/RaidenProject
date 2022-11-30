#pragma once

class AdstractScene {
public:

	//�`��ȊO�̍X�V����������. �v���C���[�̓���
	virtual void Update() = 0;

	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const = 0;

	//�V�[���؂�ւ����f
	virtual AdstractScene* ChangeScene() = 0;
};