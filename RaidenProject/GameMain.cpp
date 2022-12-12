#include"GameMain.h"
#include"DxLib.h"

GameMain::GameMain()
{
	//deleteするのを、忘れないように
	player = new Player(); //プレイヤークラスのデータ確保
	enemy = new Enemy(); //敵クラスデータ確保
	Stage_Images = LoadGraph("images/Stage/BbackgroundImage.png"); //ステージ画像読込み
	Mileage = 0; //走行距離

}

void GameMain::Update()
{
	//ここにゲームの処理

	player->Update(); //プレイヤー処理
	enemy->Update(); //敵処理


	//ステージスクロール処理
	Mileage += player->GetPlayerSpeed();

}

void GameMain::Draw()const
{
	
	//ステージ描画
	DrawGraph(0, Mileage % 480 - 480, Stage_Images, FALSE);
	DrawGraph(0, Mileage % 480, Stage_Images, FALSE);

	enemy->Draw(); //敵表示
	player->Draw(); //プレイヤー表示
}

AdstractScene* GameMain::ChangeScene()
{
	//シーン切り替え


	if (player->LifeCheck()==TRUE) //ライフが、０以下なら
	{
		delete(player);
		delete(enemy);
		//return new Gameover()
	}

	return this;
}

void GameMain::HitCheck()
{
	
}