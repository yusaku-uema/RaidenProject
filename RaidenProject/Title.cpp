#include"Title.h"
#include"GameMain.h"
#include"DxLib.h"

Title::Title()
{
	Title_Images = LoadGraph("images/Title/Title.png"); //画像読込み
	Title_BGM = 0; //仮、BGMまだ未定
	Title_Drawingtime = 0;
}
void  Title::Update() {
    
    //文字の表示（点滅）
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
        DrawString(150, 240, "---Aボタンでゲームスタート---", GetColor(255, 0, 0));
    }

}

AdstractScene* Title::ChangeScene()
{
    if (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_A) {
        //次のシーンに移行
        return new GameMain();
    }
    return this; //自分自身のポインタを返す。　
}



