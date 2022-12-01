#include"GameMain.h"
#include"DxLib.h"

GameMain::GameMain()
{
	player = new Player(); //プレイヤークラスのデータ確保
	enemy = new Enemy();
	Stage_Images = LoadGraph("images/Stage/stage.png"); 
}

void GameMain::Update()
{
	//ここにゲームの処理

	player->Update(); //プレイヤー処理
	enemy->Update(); //敵処理

}

void GameMain::Draw()const
{
	//描画のみ

	DrawGraph(0, 0, Stage_Images, FALSE); //背景画像表示

	enemy->Draw(); //敵表示
	player->Draw(); //プレイヤー表示
}

AdstractScene* GameMain::ChangeScene()
{
	//シーン切り替え
	return this;
}

void GameMain::HitCheck()
{

}