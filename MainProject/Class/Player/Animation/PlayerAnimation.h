#pragma once
#include"SpriteRender.h"

class PlayerAnimation:public SpriteRender
{
private:
	float time;
	bool  isSwitch;
	const float END_TIME = 1;
public:
	PlayerAnimation():time(0),isSwitch(false){}
	~PlayerAnimation() = default;
	void SetDate()override;
	void UpDate()override;
	void Collision() {};

};