#include<stdio.h>
#include"SceneManager.h"


//コンストラクタ   初期化
SceneManager::SceneManager(AdstractScene* scene)
{
	m_Scene = scene; //子どものクラスのデータをm_Sceneに入れる 
}

void SceneManager::Update()
{
	//InputManager::Update();
	m_Scene->Update(); 
	// -> アロー演算子   アクセス    ポインタだから->   
}


void SceneManager::Draw()const
{
	m_Scene->Draw(); 
}


void SceneManager::ChangeScene() //同じシーンなのか？
{
	AdstractScene* next = m_Scene->ChangeScene();
	if (next != m_Scene)  //m_Sceneとnextは一緒ですか?
	{
		delete m_Scene; //タイトル消去
		m_Scene = next; //次のシーンに移行
	}

	// new()でメモリ確保したら　deleteで必ず消す。
}
