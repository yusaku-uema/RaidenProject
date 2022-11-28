#include"Title.h"
#include"GameMain.h"
#include"DxLib.h"

Title::Title()
{
	Title_Images = LoadGraph("images/Title/Title.png"); //�摜�Ǎ���
	Title_BGM = 0; //���ABGM�܂�����
	Title_Drawingtime = 0;
}
void  Title::Update() {
    
    //�����̕\���i�_�Łj
    Title_Drawingtime++; 
     if (Title_Drawingtime > 60)
    {
        Title_Drawingtime = 0;
    }
}

void Title::Draw() const {
    DrawGraph(0, 0, Title_Images, FALSE);
    SetFontSize(25);
    if (Title_Drawingtime < 30)
    {
        DrawString(150, 240, "---A�{�^���ŃQ�[���X�^�[�g---", GetColor(255, 0, 0));
    }

}

AdstractScene* Title::ChangeScene()
{
    if (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_A) {
        //���̃V�[���Ɉڍs
        return new GameMain();
    }
    return this; //�������g�̃|�C���^��Ԃ��B�@
}



