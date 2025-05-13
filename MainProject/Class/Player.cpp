#include "Player.h"

void Player::SetDate()
{
	SetImagesNumber(Vector2(9, 1), PlayerID);

	SetPosition
	(
		//Œ´“_‚ª^‚ñ’†‚Ìˆ×ˆÚ“®
		Vector2
		(
			(float)GetSprite(BackGroundForest).size.x / 2.0f,
			(float)DXTK->SwapChain.Height / 2.0f
		),
		BackGroundForest
	);
}

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