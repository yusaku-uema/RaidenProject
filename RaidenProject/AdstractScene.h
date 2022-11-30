#pragma once

class AdstractScene {
public:

	//描画以外の更新を実装する. プレイヤーの動き
	virtual void Update() = 0;

	//描画に関することを実装する
	virtual void Draw() const = 0;

	//シーン切り替え判断
	virtual AdstractScene* ChangeScene() = 0;
};