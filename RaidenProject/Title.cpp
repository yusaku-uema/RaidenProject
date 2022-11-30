#include"Title.h"
#include"GameMain.h"
#include"DxLib.h"

Title::Title()
{
	Title_Images = LoadGraph("images/Title/Title.png"); //画像読込み
	Title_BGM = LoadSoundMem("BGM/Title.mp3"); //BGM読込み
	Title_Drawingtime = 0; //描画時間初期化
}
void  Title::Update()
{
	//文字の表示（点滅）
	Title_Drawingtime++;  //描画時間を +１していく

	if (Title_Drawingtime > 60) 
	{
		Title_Drawingtime = 0; //リセット
	}

	if (CheckSoundMem(Title_BGM) != 1) {   //BGMが流れていなかったら再生
		ChangeVolumeSoundMem(255 * 80 / 100, Title_BGM); //BGM音量調整 255最大音量から80%再生する。
		PlaySoundMem(Title_BGM, DX_PLAYTYPE_LOOP, TRUE); //BGM再生
	}
}

void Title::Draw() const
{

	DrawGraph(0, 0, Title_Images, FALSE); //背景画像表示

	SetFontSize(60); //フォントサイズ変更
	DrawString(100, 120, "雷電プロジェクト", GetColor(255, 0, 0)); //文字表示

	SetFontSize(30);//フォントサイズ変更
	if (Title_Drawingtime < 30) //３０より小さい間、文字描画する。
	{
		DrawString(120, 260, "---Aボタンでゲームスタート---", GetColor(255, 255, 255)); //文字の描画
	}

}

AdstractScene* Title::ChangeScene()
{
	if (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_A)
	{ //パットのAボタンが押されたら

	  //次のシーンに移行
		return new GameMain(); //ゲームメインに移行
	}
	return this; //自分自身のポインタを返す。　
}



