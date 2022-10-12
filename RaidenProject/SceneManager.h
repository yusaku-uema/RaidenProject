#pragma once
#include"AdstractScene.h"

//シーンマネージャークラス
//各シーンの切り替えを管理する。
class SceneManager : public AdstractScene {
private:
	AdstractScene* mScene; //現在のシーン

public:
	//コンストラクタ
	SceneManager(AdstractScene* scene) :mScene(scene) {}

	//デストラクタ
	~SceneManager() {
		delete mScene;
	}

	//描画以外の更新を実装する
	AdstractScene* Update() override;

	//描画に関することを実装する
	void Draw() const override;
};