#include"Player.h"
#include"DxLib.h"

player::player() {

	Score = 0;
	Life = 0;
	Player_X = 0;
	Player_Y = 0;
	imagesnum = 0;
	LoadDivGraph("images/Player/Zerofighter plane.png", 4, 32, 1, 32, 32, Player_images);

}

AdstractScene* player::Update() {
	if (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_LEFT) --Player_X; //ç∂
	if (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_RIGHT) ++Player_X; //âE
	if (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_UP) --Player_Y; //è„
	if (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_DOWN) ++Player_Y; //â∫
	return this;
}

void player::Draw() const {

	DrawGraph(Player_X ,Player_Y, Player_images[imagesnum], TRUE);
}

