#include "Recovery.h"
#include"DxLib.h"

Recovery::Recovery()
{
	location.x = 0;
	location.y = 0;
	radius = 10;
	Reset = true;
	images = LoadGraph("images/item/spana.png");
	type = 0;
	speed = 5;
}

void Recovery::Update()
{
	if (Reset == true)
	{
		location.x = GetRand(570) + 50;
		location.y = GetRand(-100) - 20;
		type = GetRand(15) + 4;
		Reset = false;
	}
	else
	{
		location.y += speed;
	}
	if (location.y > 500)
	{
		Reset = true;
	}
}

void Recovery::Draw()const
{
	DrawRotaGraph(location.x, location.y, 1.5f, 0, images, TRUE); //“G•\Ž¦
}

void Recovery::SetReset()
{
	Reset = true;
}

bool Recovery::HitCheck(Player* player)
{

	bool ret = false; //–ß‚è’l

	if (HitSphere(player) == true)
	{
		ret = true;
	}
	return ret;

}