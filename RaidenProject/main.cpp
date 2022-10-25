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

    // �^�C�g���� test �ɕύX
    SetMainWindowText("���d�v���W�F�N�g");

    ChangeWindowMode(TRUE);		// �E�B���h�E���[�h�ŋN��

    SetGraphMode(1280, 720, 16); //�E�B���h�E�T�C�Y��ݒ�

    if (DxLib_Init() == -1) return -1;	// DX���C�u�����̏���������

    SetDrawScreen(DX_SCREEN_BACK);	// �`����ʂ𗠂ɂ���

    SceneManager sceneMng(new Title()); 

    while (ProcessMessage() == 0 && Forcedtermination != true && sceneMng.Update() != nullptr) {
        // �Q�[���p�b�g��BACK�{�^�������ꂽ�狭���I��
        if (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_7) { 
            Forcedtermination = true; //�t���O��True��
        }

        ClearDrawScreen();		// ��ʂ̏�����

        sceneMng.Draw();

        ScreenFlip();			// ����ʂ̓��e��\��ʂɔ��f

    }

    DxLib_End();	// DX���C�u�����g�p�̏I������

    return 0;	// �\�t�g�̏I��
}