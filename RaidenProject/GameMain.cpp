#include"GameMain.h"
#include"DxLib.h"

GameMain::GameMain()
{
	player = new Player(); //プレイヤークラスのデータ確保
	Stage_Images = LoadGraph("images/Stage/stage.png"); 
}

void GameMain::Update()
{
	//ここにゲームの処理

	player->Update(); 

}

void GameMain::Draw()const
{
	//描画のみ

	DrawGraph(0, 0, Stage_Images, FALSE); //背景画像表示

	player->Draw();
}

AdstractScene* GameMain::ChangeScene()
{
	//シーン切り替え
	return this;
}

void GameMain::HitCheck()
{

}