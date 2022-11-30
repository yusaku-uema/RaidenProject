#include"GameMain.h"

GameMain::GameMain()
{

}

void  GameMain::Update()
{
	//ここにゲームの処理を記述

	player->Update();


}

void GameMain::Draw()const
{
	//描画のみ

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