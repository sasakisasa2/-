#include "PlayerAnimation.h"

void PlayerAnimation::SetDate()
{
	SetImagesNumber(Vector2(9, 1), PlayerID);
}

void PlayerAnimation::UpDate()
{
	Vector2 count = GetImagesCount(PlayerID);

	time += DXTK->Time.deltaTime;

	if (time >= END_TIME)
	{
		time = 0.0f;

		if (isSwitch) { count.x--; }
		else          { count.x++; }
		
		if (count.x == GetImagesNumber(PlayerID).x)
			isSwitch = true;
		if (count.x == 0.0f)
			isSwitch = false;
	}

	SetImagesCount(count, PlayerID);
}