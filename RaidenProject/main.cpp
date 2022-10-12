/********************************************************************
**	��1�́@�����ŃQ�[��������Ă�����
**	�@���d�v���W�F�N�g
********************************************************************/
#include "DxLib.h"
#include"AdstractScene.h"
#include"SceneManager.h"

/***********************************************
 * �v���O�����̊J�n
 ***********************************************/
int	g_Key; //���̓L�[

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

    SceneManager sceneMng();

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {  //sceneMng.Update() != nullptr

        // ���̓L�[�擾   
        g_Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

        ClearDrawScreen();		// ��ʂ̏�����

        ScreenFlip();			// ����ʂ̓��e��\��ʂɔ��f
    }

    DxLib_End();	// DX���C�u�����g�p�̏I������

    return 0;	// �\�t�g�̏I��
}