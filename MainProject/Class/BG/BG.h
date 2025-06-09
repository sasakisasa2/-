#pragma once
#include"GameObject.h"

using namespace DirectX;
using namespace SimpleMath;

class BG:public GameObject
{
private:

	float speed;


public:
	BG():speed(500.0f){ }
	void SetDate()override;
	void UpDate()override;
	void Collision() {};
};