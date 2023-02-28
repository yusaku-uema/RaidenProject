#include"GameMain.h"
#include"DxLib.h"
#include"CharaBase.h"


//コンストラクタ
GameMain::GameMain()
{
	//deleteするのを、忘れないように

	player = new Player(); //プレイヤークラスのデータ確保

	//for (int i = 0; i < EnemyMax; i++) {
		//enemy[i] = new Enemy(); //敵クラスデータ確保
	//}
	enemy = new Enemy();
	Stage_Images = LoadGraph("images/Stage/BbackgroundImage.png"); //ステージ画像読込み
	Mileage = 0; //走行距離

}

//デストラクタ
GameMain::~GameMain()
{
	delete player;
	delete enemy;

}
void GameMain::Update()
{
	//ここにゲームの処理

	player->Update(); //プレイヤー処理
	//敵処理
	/*for (int i = 0; i < EnemyMax; i++)
	{
		enemy[i]->Update();
	}*/
	enemy->Update();

	//プレイヤーの弾が敵に当たったら
	//for (int i = 0; i < EnemyMax; i++)
	//{
	//	for (int j = 0; j < 100; j++)
	//	{
	//		if (enemy[i]->HitCheck(player->GetBullet(j)))
	//		{
	//			if (player->GetRest(j) == false)
	//			{
	//				player->SetBullet(j); //弾丸消去
	//				enemy[i]->Hit(10); //HPを引く
	//			}

	//		}

	//	}
	//}

	//ステージスクロール処理
	Mileage += player->GetPlayerSpeed();



}

void GameMain::Draw()const
{

	//ステージ描画
	DrawGraph(0, Mileage % 480 - 480, Stage_Images, FALSE);//画像が続いているように見えるように描画
	DrawGraph(0, Mileage % 480, Stage_Images, FALSE);//描画
	for (int i = 0; i < EnemyMax; i++)
	{
		enemy->Draw(); //敵表示
	}

	player->Draw(); //プレイヤー表示
}

AdstractScene* GameMain::ChangeScene()
{
	//シーン切り替え


	if (player->LifeCheck() == TRUE) //ライフが、０以下なら
	{
		//return new Gameover()
	}

	return this;
}

void GameMain::HitCheck()
{

}

