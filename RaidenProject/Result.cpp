#include "Result.h"
#include"Title.h"
#include"DxLib.h"

Result::Result(int a)
{
	Result_Drawingtime = 0; //描画時間初期化
	Enemy_num = a;
}
Result::~Result()
{

}
void  Result::Update()
{
	//文字の表示（点滅）
	Result_Drawingtime++;  //描画時間を +１していく

	if (Result_Drawingtime > 60) //61になったらif分の中の処理をおこなう。
	{
		Result_Drawingtime = 0; //リセット
	}
}

void  Result::Draw() const
{

	SetFontSize(60); //フォントサイズ変更
	DrawString(100, 120, "倒した敵の数 ", GetColor(255, 0, 0)); //文字表示
	DrawFormatString(500, 120, 0xFFFFFF, "%d", Enemy_num);

	SetFontSize(30);//フォントサイズ変更
	if (Result_Drawingtime < 30) //３０より小さい間、文字描画する。
	{
		DrawString(120, 260, "---Bボタンでタイトル", GetColor(255, 255, 255)); //文字の描画
	}
	
}

AdstractScene* Result::ChangeScene()
{
	if (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B)
	{
	  //次のシーンに移行
		return new Title(); //ゲームメインに移行
	}

	return this; //自分自身のポインタを返す。　
}