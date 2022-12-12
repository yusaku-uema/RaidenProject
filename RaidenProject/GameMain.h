#pragma once
#include"AdstractScene.h"
#include"Player.h"
#include"Enemy.h"


class GameMain : public AdstractScene
{
private:
	//インターネットにあった他のクラスの参照,https://cpp-lang.sevendays-study.com/ex-day2.html
	Player* player;
	Enemy* enemy;

	int Stage_Images; //ステージ画像
	int Mileage; //走行距離

public:

	//コンストラクタ
	GameMain();

	//描画以下の更新を実施する
	void Update() override;

	//描画に関することを実装する
	void Draw() const override;

	//シーン切り替え
	AdstractScene* ChangeScene() override;

	//当たり判定
	void HitCheck();

};
