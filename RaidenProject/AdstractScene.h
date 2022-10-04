#pragma once

class AdstractScene {
public:
	//�f�X�g���N�^
	virtual ~AdstractScene() {};

	//�`��ȊO�̍X�V����������. �v���C���[�̓���
	virtual AdstractScene* Update() = 0;

	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const = 0;
};