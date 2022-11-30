#include"Title.h"
#include"GameMain.h"
#include"DxLib.h"

Title::Title()
{
	Title_Images = LoadGraph("images/Title/Title.png"); //�摜�Ǎ���
	Title_BGM = LoadSoundMem("BGM/Title.mp3"); //BGM�Ǎ���
	Title_Drawingtime = 0; //�`�掞�ԏ�����
}
void  Title::Update()
{
	//�����̕\���i�_�Łj
	Title_Drawingtime++;  //�`�掞�Ԃ� +�P���Ă���

	if (Title_Drawingtime > 60) 
	{
		Title_Drawingtime = 0; //���Z�b�g
	}

	if (CheckSoundMem(Title_BGM) != 1) {   //BGM������Ă��Ȃ�������Đ�
		ChangeVolumeSoundMem(255 * 80 / 100, Title_BGM); //BGM���ʒ��� 255�ő剹�ʂ���80%�Đ�����B
		PlaySoundMem(Title_BGM, DX_PLAYTYPE_LOOP, TRUE); //BGM�Đ�
	}
}

void Title::Draw() const
{

	DrawGraph(0, 0, Title_Images, FALSE); //�w�i�摜�\��

	SetFontSize(60); //�t�H���g�T�C�Y�ύX
	DrawString(100, 120, "���d�v���W�F�N�g", GetColor(255, 0, 0)); //�����\��

	SetFontSize(30);//�t�H���g�T�C�Y�ύX
	if (Title_Drawingtime < 30) //�R�O��菬�����ԁA�����`�悷��B
	{
		DrawString(120, 260, "---A�{�^���ŃQ�[���X�^�[�g---", GetColor(255, 255, 255)); //�����̕`��
	}

}

AdstractScene* Title::ChangeScene()
{
	if (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_A)
	{ //�p�b�g��A�{�^���������ꂽ��

	  //���̃V�[���Ɉڍs
		return new GameMain(); //�Q�[�����C���Ɉڍs
	}
	return this; //�������g�̃|�C���^��Ԃ��B�@
}



