#pragma once
#include"SpriteRender.h"

using namespace DirectX;
using namespace SimpleMath;

class Player:public SpriteRender
{
private:

	float speed;


public:
	Player():speed(100.0f){ }
	~Player() { Initialize(PlayerID); }
	void SetDate()override;
	void UpDate()override;

};