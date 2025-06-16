#include "BG.h"

void BG::SetDate(int count)
{
	SetPosition
	(
		//Œ´“_‚ª^‚ñ’†‚Ìˆ×ˆÚ“®
		Vector2
		(
			(float)GetSprite(BGID).size.x / 2.0f,
			(float)DXTK->SwapChain.Height / 2.0f
		),
		BGID
	);
}

void BG::UpDate(int count)
{
	Vector2 pos = GetPosition(BGID,count);

	pos.x -= speed * DXTK->Time.deltaTime;
	
	if (pos.x <= -(float)DXTK->SwapChain.Width / 2.0f)
	{
		pos.x = (float)GetSprite(BGID).size.x / 2.0f;
	}

	SetPosition(pos, BGID,count);
}