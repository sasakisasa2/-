#pragma once
#include"SpriteRender.h"

using namespace DirectX;
using namespace SimpleMath;

class BG:public SpriteRender
{
private:

	float speed;


public:
	BG():speed(500.0f){ }
	void SetDate()override;
	void UpDate()override;
	void Collision() {};
};