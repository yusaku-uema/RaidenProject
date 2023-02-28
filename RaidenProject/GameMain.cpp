#include"GameMain.h"
#include"DxLib.h"
#include"CharaBase.h"
#include"Result.h"


//コンストラクタ
GameMain::GameMain()
{
	//deleteするのを、忘れないように

	player = new Player(); //プレイヤークラスのデータ確保

	for (int i = 0; i < EnemyMax; i++) 
	{
		enemy[i] = new Enemy(); //敵クラスデータ確保
	}
	Stage_Images = LoadGraph("images/Stage/BbackgroundImage.png"); //ステージ画像読込み
	Mileage = 0; //走行距離
	BullersTime = 1;
	BullersNum = 0;
	Enemy_num = 0;
}

//デストラクタ
GameMain::~GameMain()
{
	delete player;
	delete enemy;

}
void GameMain::Update()
{

	player->Update(); //プレイヤー処理

	//敵処理
	for (int i = 0; i < EnemyMax; i++)
	{
		enemy[i]->Update();
	}

	//プレイヤーの弾が敵に当たったら
	for (int i = 0; i < EnemyMax; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (enemy[i]->HitCheck(player->GetBullet(j)))
			{
				if (player->GetRest(j) == false)
				{
					player->SetBullet(j); //弾丸消去
					enemy[i]->Hit(10); //HPを引く
					if (enemy[i]->HPCheck() == true)Enemy_num++;
				}

			}

		}
	}

	//敵の弾丸に当たったら
	for (int i = 0; i < EnemyMax; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (player->HitCheck(enemy[i]->GetBullet(j)))
			{
				if (enemy[i]->GetBullet(j)->GetReset() == false)
				{
					enemy[i]->GetBullet(j)->SetReset(true);
					player->Hit(1);
				}
			}
		}
	}

	//弾丸を増やして行く。
	if (BullersTime++ % 120 == 0)
	{
		BullersNum++;
	}
	if (BullersNum > 100)
	{
		BullersNum = 0;
	}


	//弾丸生成
	for (int i = 0; i < EnemyMax; i++)
	{
		for (int j = 0; j < BullersNum; j++)
		{
			enemy[i]->GetBullet(j)->SetBullers(player->GetLocation().x, player->GetLocation().y,enemy[i]->GetLocation().x, enemy[i]->GetLocation().y);
		}
	}

	//弾丸の更新
	for (int i = 0; i < EnemyMax; i++)
	{
		for (int j = 0; j < BullersNum; j++)
		{
			enemy[i]->GetBullet(j)->Update();
		}

	}
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
		enemy[i]->Draw(); //敵表示
		for (int  j = 0; j < 100; j++)
		{
			enemy[i]->GetBullet(j)->Draw();
		}
	}

	player->Draw(); //プレイヤー表示
}

AdstractScene* GameMain::ChangeScene()
{
	//シーン切り替え


	if (player->LifeCheck() == TRUE) //ライフが、０以下なら
	{
		return new  Result(Enemy_num);
	}

	return this;
}

void GameMain::HitCheck()
{

}

