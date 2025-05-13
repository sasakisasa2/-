#include "Player.h"

void Player::SetDate()
{ }

void Player::UpDate()
{
	Vector2 pos = GetPosition(BackGroundForest);

	pos.x -= speed * DXTK->Time.deltaTime;
	
	if (pos.x <= -(float)DXTK->SwapChain.Width / 2.0f)
	{
		pos.x = (float)GetSprite(BackGroundForest).size.x / 2.0f;
	}

	SetPosition(pos, BackGroundForest);
}