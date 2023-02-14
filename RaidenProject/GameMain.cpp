#include"GameMain.h"
#include"DxLib.h"


//メモ
//条件式の不等号は統一するほうがよい
//例　　if(a < b)  < の向きで統一する　記述日01/11日4時間目
//これ以降は 不等号の向きを　<　の向きでよろしく。


//コンストラクタ
GameMain::GameMain()
{
	//deleteするのを、忘れないように
	player = new Player(); //プレイヤークラスのデータ確保
	for (int i = 0; i < EnemyMax; i++) {
		enemy[i] = new Enemy(); //敵クラスデータ確保
	}
	Stage_Images = LoadGraph("images/Stage/BbackgroundImage.png"); //ステージ画像読込み
	Mileage = 0; //走行距離

}

//デストラクタ
GameMain::~GameMain()
{
	delete player;
	for (int i = 0; i < EnemyMax; i++) {
		delete enemy[i];
	}
	
}
void GameMain::Update()
{
	//ここにゲームの処理

	player->Update(); //プレイヤー処理
	//敵処理
	for (int i = 0; i < EnemyMax; i++) {
		enemy[i]->Update();
	}
	 
	//ステージスクロール処理
	Mileage += player->GetPlayerSpeed();

}

void GameMain::Draw()const
{
	
	//ステージ描画
	DrawGraph(0, Mileage % 480 - 480, Stage_Images, FALSE);//画像が続いているように見えるように描画
	DrawGraph(0, Mileage % 480, Stage_Images, FALSE);//描画
	for (int i = 0; i < EnemyMax; i++) {
		enemy[i]->Draw(); //敵表示
	}
	
	player->Draw(); //プレイヤー表示
}

AdstractScene* GameMain::ChangeScene()
{
	//シーン切り替え


	if (player->LifeCheck()==TRUE) //ライフが、０以下なら
	{
		//return new Gameover()
	}

	return this;
}

void GameMain::HitCheck()
{
	
}

