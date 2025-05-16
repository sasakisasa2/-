#pragma once
#include"SpriteRender.h"

using namespace DirectX;
using namespace SimpleMath;

class PlayerAnimation:public SpriteRender
{
private:
	float time;
	const float endTime = 1;
public:
	PlayerAnimation():time(0){}
	~PlayerAnimation() { Initialize(PlayerID); }
	void SetDate()override;
	void UpDate()override;

};