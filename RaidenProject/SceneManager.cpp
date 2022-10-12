#include<stdio.h>
#include"SceneManager.h"

AdstractScene* SceneManager::Update() {
	AdstractScene* p = mScene->Update();
	if (p != mScene) {
		delete mScene;
		mScene = p;
	}
	return p;
}

void SceneManager::Draw() const {
	mScene->Draw();
}
