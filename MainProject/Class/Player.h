#pragma once
#include"SpriteRender.h"
#include"PlayerAnimation.h"

using namespace DirectX;
using namespace SimpleMath;

class Player:public SpriteRender
{
private:

	float speed;
	PlayerAnimation anime;

public:
	Player():speed(500.0f){ }
	~Player() { Initialize(PlayerID); }
	void SetDate()override;
	void UpDate()override;

};