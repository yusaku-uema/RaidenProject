#include "PlayerBullers.h"
#include"Player.h"

PlayerBullers::PlayerBullers()
{
	location.x = 0;
	location.y = 0;
}

void PlayerBullers::Update()
{
	if (Shooting_Time++ % 10 == 0)//’eŠÛ”­ŽËŠÔŠu
	{
		for (int i = 0; i < 100; i++)
		{
			if (Shooting_Flag == TRUE) {
				/*if (bullets[i] == nullptr)
				{
					bullets[i]->SettingBullets(Player_X, Player_Y - 18);
				}*/
				bullets[i]->SettingBullets(Player_X, Player_Y - 18);
			}
		}

	}
}
