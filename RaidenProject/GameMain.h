#pragma once
#include"AdstractScene.h"
#include"Title.h" //テスト

class GameMain : public AdstractScene 
{
private:
	float *player; //ポインタ変数
	int *enemy[5]; //ポインタ配列
public:
	Title* test;
	GameMain();

	//描画以下の更新を実施する
	virtual AdstractScene* Update() override;

	//描画に関することを実装する
	virtual void Draw() const override;

	void HitCheck(); //当たり判定


};
