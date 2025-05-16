#include "PlayerAnimation.h"

void PlayerAnimation::SetDate()
{
	SetImagesNumber(Vector2(9, 1), PlayerID);
}

void PlayerAnimation::UpDate()
{
	Vector2 count = GetImagesCount(PlayerID);

	time += DXTK->Time.deltaTime;
}