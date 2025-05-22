#pragma once
#include"Player.h"

using namespace DirectX;
using namespace SimpleMath;

class PlayerAnimation:public Player
{
private:
	float time;
	bool  isSwitch;
	const float END_TIME = 1;
public:
	PlayerAnimation():time(0),isSwitch(false){}
	~PlayerAnimation() { Initialize(PlayerID); }
	void SetDate()override;
	void UpDate()override;

};