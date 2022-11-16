#include<stdio.h>
#include"SceneManager.h"

SceneManager::SceneManager(AdstractScene* scene)
{
	m_Scene = scene; //�q�ǂ��̃N���X�̃f�[�^��m_Scene�ɓ���� 
}
//�R���X�g���N�^   ������


void SceneManager::Update()
{
	//InputManager::Update();
	m_Scene->Update(); 
	// -> �A���[���Z�q   �A�N�Z�X    �|�C���^������->   
}


void SceneManager::Draw()const
{
	m_Scene->Draw(); 
}


void SceneManager::ChangeScene() //�����V�[���Ȃ̂��H
{
	AdstractScene* next = m_Scene->ChangeScene();
	if (next != m_Scene)  //m_Scene��next�͈ꏏ�ł���?
	{
		delete m_Scene; //�^�C�g������
		m_Scene = next; //���̃V�[���Ɉڍs
	}

	// new()�Ń������m�ۂ�����@delete�ŕK�������B
}
