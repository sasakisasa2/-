#include "PlayerAnimation.h"

void PlayerAnimation::SetDate()
{
	SetImagesNumber(Vector2(9, 1), PlayerID,0);
}

void PlayerAnimation::UpDate()
{
	time += DXTK->Time.deltaTime;

	if (time >= END_TIME)
	{
		Vector2 imageCount = GetImagesCount(PlayerID, 0);

		time = 0.0f;

		if (isSwitch) { imageCount.x--; }
		else          { imageCount.x++; }
		
		if (imageCount.x == GetImagesNumber(PlayerID,0).x-1)
			isSwitch = true;
		if (imageCount.x == 0.0f)
			isSwitch = false;

		SetImagesCount(imageCount, PlayerID,0);
	}
}