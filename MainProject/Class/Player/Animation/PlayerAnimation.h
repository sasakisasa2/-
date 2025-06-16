#pragma once
#include"../MainProject/Class/GameObject/GameObject.h"

class PlayerAnimation:public GameObject
{
private:
	float time;
	bool  isSwitch;
	const float END_TIME = 1;
public:
	PlayerAnimation():time(0),isSwitch(false){}
	~PlayerAnimation()override = default;
	void SetDate  (int count)override;
	void UpDate   (int count)override;
	void Collision(int count)override {};
};