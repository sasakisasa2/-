#pragma once
#include"SpriteRender.h"

using namespace DirectX;
using namespace SimpleMath;

class PlayerAnimation:public SpriteRender
{
private:

public:
	PlayerAnimation() = default;
	~PlayerAnimation() { Initialize(PlayerID); }
	void SetDate()override;
	void UpDate()override;

};