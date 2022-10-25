#include"Title.h"
#include"GameMain.h"
#include"DxLib.h"

Title::Title()
{
	Title_images = LoadGraph("images/Title/Title.png");
	Title_bgm = 0; //��
	Title_Drawingtime = 0;
}

AdstractScene* Title::Update() {
    //�����̕\���i�_�Łj
  
    Title_Drawingtime++;
     if (Title_Drawingtime > 60)
    {
        Title_Drawingtime = 0;
    }

    if (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_A) {
        //���̃V�[���Ɉڍs
        return new GameMain();
    }
    return this;
}

void Title::Draw() const {
    DrawGraph(0, 0, Title_images, FALSE);
    SetFontSize(64);
    if (Title_Drawingtime < 30)
    {
        DrawString(150, 455, "---A�{�^���ŃQ�[���X�^�[�g---", GetColor(255, 0, 0));
    }

}




