#pragma once

class AdstractScene {
public:
	//デストラクタ
	virtual ~AdstractScene() {};

	//描画以外の更新を実装する. プレイヤーの動き
	virtual AdstractScene* Update() = 0;

	//描画に関することを実装する
	virtual void Draw() const = 0;
};