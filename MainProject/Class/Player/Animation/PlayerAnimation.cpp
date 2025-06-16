#include "PlayerAnimation.h"

void PlayerAnimation::SetDate(int count)
{
	SetImagesNumber(Vector2(9, 1), PlayerID,count);
}

void PlayerAnimation::UpDate(int count)
{
	time += DXTK->Time.deltaTime;

	if (time >= END_TIME)
	{
		Vector2 imageCount = GetImagesCount(PlayerID, count);

		time = 0.0f;

		if (isSwitch) { imageCount.x--; }
		else          { imageCount.x++; }
		
		if (imageCount.x == GetImagesNumber(PlayerID,count).x-1)
			isSwitch = true;
		if (imageCount.x == 0.0f)
			isSwitch = false;

		SetImagesCount(imageCount, PlayerID,count);
	}
}