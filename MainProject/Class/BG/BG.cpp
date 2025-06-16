#include "BG.h"

void BG::SetDate()
{
	SetPosition
	(
		//Œ´“_‚ª^‚ñ’†‚Ìˆ×ˆÚ“®
		Vector2
		(
			(float)GetSprite(BGID).size.x / 2.0f,
			(float)DXTK->SwapChain.Height / 2.0f
		),
		BGID,
		0
	);
}

void BG::UpDate()
{
	Vector2 pos = GetPosition(BGID,0);

	pos.x -= speed * DXTK->Time.deltaTime;
	
	if (pos.x <= -(float)DXTK->SwapChain.Width / 2.0f)
	{
		pos.x = (float)GetSprite(BGID).size.x / 2.0f;
	}

	SetPosition(pos, BGID,0);
}