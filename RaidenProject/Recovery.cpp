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
	time = 1;
}

void Recovery::Update()
{
	if (time++ % 300 == 0)
	{
		if (Reset == true)
		{
			location.x = GetRand(570) + 50;
			location.y = GetRand(390) + 10;
			type = GetRand(6) + 1;
			Reset = false;
		}
	}
	if (location.y > 500)
	{
		Reset = true;
	}
}

void Recovery::Draw()const
{
	if(Reset != true)DrawRotaGraph(location.x, location.y, 1.5f, 0, images, TRUE); //“G•\Ž¦
}

void Recovery::SetReset()
{
	Reset = true;
}

bool Recovery::HitCheck(PlayerBullers* playerbullers)
{

	bool ret = false; //–ß‚è’l

	if (HitSphere(playerbullers) == true)
	{
		ret = true;
	}
	return ret;

}