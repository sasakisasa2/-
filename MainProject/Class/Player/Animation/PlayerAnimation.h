#pragma once
#include"GameObject.h"

class PlayerAnimation:public GameObject
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