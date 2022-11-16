#include"Title.h"
#include"GameMain.h"
#include"DxLib.h"

Title::Title()
{
	Title_images = LoadGraph("images/Title/Title.png"); //画像読込み
	Title_bgm = 0; //仮
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
    DrawGraph(0, 0, Title_images, FALSE);
    SetFontSize(64);
    if (Title_Drawingtime < 30)
    {
        DrawString(150, 455, "---Aボタンでゲームスタート---", GetColor(255, 0, 0));
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



