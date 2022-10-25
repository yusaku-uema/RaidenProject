#include"Player.h"
#include"DxLib.h"

player::player() {
	score = 0;
	life = 0;
}

AdstractScene* player::Update() {
	return this;
}

void player::Draw() const {

}

