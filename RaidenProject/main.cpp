/********************************************************************
**	��1�́@�����ŃQ�[��������Ă�����
**	�@���d�v���W�F�N�g
********************************************************************/
#include "DxLib.h"
#include"AdstractScene.h"
#include"SceneManager.h"
#include"Title.h"

/***********************************************
 * �ϐ�
 ***********************************************/
bool Forcedtermination = false; //�����I���t���O

/***********************************************
 * �v���O�����̊J�n
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow) {

    // �^�C�g���� ���d�v���W�F�N�g�ɕύX
    SetMainWindowText("���d�v���W�F�N�g");

    ChangeWindowMode(TRUE);		// �E�B���h�E���[�h�ŋN��

    SetGraphMode(640, 480, 16); //�E�B���h�E�T�C�Y��ݒ�  
    //���A�c�A�J���[�r�b�g���@32�ɂ���Ə������d���Ȃ�

    if (DxLib_Init() == -1) return -1;	// DX���C�u�����̏���������

    SetDrawScreen(DX_SCREEN_BACK);	// �`����ʂ𗠂ɂ���

    SceneManager* sceneManager = new SceneManager(new Title()); //�ŏ��ɌĂяo���V�[��

    while (ProcessMessage() == 0 && Forcedtermination != true) {
        
        // �Q�[���p�b�g��BACK�{�^�������ꂽ�狭���I��
        if (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_7) { 
            Forcedtermination = true; //�t���O��True��
        }

        sceneManager->Update(); //�`��ȊO

        ClearDrawScreen();		// ��ʂ̏�����

        sceneManager->Draw(); //�`��̂�

        ScreenFlip();			// ����ʂ̓��e��\��ʂɔ��f

        sceneManager->ChangeScene(); //�V�[���؂�ւ�
    }

    DxLib_End();	// DX���C�u�����g�p�̏I������

    return 0;	// �\�t�g�̏I��
}