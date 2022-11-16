#pragma once
#include"AdstractScene.h"

//シーンマネージャークラス
//各シーンの切り替えを管理する。
//シーンの切り替え担当
class SceneManager
{
private:
	AdstractScene* m_Scene;

public:
	SceneManager(AdstractScene* scene);

public:
	void Update();
	void Draw()const;
	void ChangeScene();
};