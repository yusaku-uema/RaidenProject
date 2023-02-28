#pragma once
#include"AdstractScene.h"
#include"Player.h"
#include"PlayerBullers.h"
#include"Enemy.h"
#include"BulletsBase.h"
#include"Recovery.h"

#define PLAYER_BULLETS 100 //プレイヤーの弾丸の数

class GameMain : public AdstractScene
{
private:
	//インターネットにあった他のクラスの参照,https://cpp-lang.sevendays-study.com/ex-day2.html
	Player* player;
	Enemy* enemy[EnemyMax];
	Recovery* recovery;
	int Stage_Images; //ステージ画像
	int Mileage; //走行距離
	int BullersNum; //弾丸の数
	int BullersTime; //時間が経過するごとに弾丸数が増える。
	int Enemy_num; //倒した敵

public:

	//コンストラクタ
	GameMain();

	//デストラクタ
	~GameMain();

	//描画以下の更新を実施する
	void Update() override;

	//描画に関することを実装する
	void Draw() const override;

	//シーン切り替え
	AdstractScene* ChangeScene() override;

	//当たり判定
	void HitCheck();

};
