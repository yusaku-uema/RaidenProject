#include "Result.h"
#include"Title.h"
#include"DxLib.h"

Result::Result(int a)
{
	Result_Drawingtime = 0; //�`�掞�ԏ�����
	Enemy_num = a;
}
Result::~Result()
{

}
void  Result::Update()
{
	//�����̕\���i�_�Łj
	Result_Drawingtime++;  //�`�掞�Ԃ� +�P���Ă���

	if (Result_Drawingtime > 60) //61�ɂȂ�����if���̒��̏����������Ȃ��B
	{
		Result_Drawingtime = 0; //���Z�b�g
	}
}

void  Result::Draw() const
{

	SetFontSize(60); //�t�H���g�T�C�Y�ύX
	DrawString(100, 120, "�|�����G�̐� ", GetColor(255, 0, 0)); //�����\��
	DrawFormatString(500, 120, 0xFFFFFF, "%d", Enemy_num);

	SetFontSize(30);//�t�H���g�T�C�Y�ύX
	if (Result_Drawingtime < 30) //�R�O��菬�����ԁA�����`�悷��B
	{
		DrawString(120, 260, "---B�{�^���Ń^�C�g��", GetColor(255, 255, 255)); //�����̕`��
	}
	
}

AdstractScene* Result::ChangeScene()
{
	if (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B)
	{
	  //���̃V�[���Ɉڍs
		return new Title(); //�Q�[�����C���Ɉڍs
	}

	return this; //�������g�̃|�C���^��Ԃ��B�@
}