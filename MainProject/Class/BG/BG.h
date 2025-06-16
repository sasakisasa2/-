#pragma once
#include"../GameObject/GameObject.h"

using namespace DirectX;
using namespace SimpleMath;

class BG:public GameObject
{
private:

	float speed;


public:
	BG():speed(500.0f){ }
	void SetDate  (int count)override;
	void UpDate   (int count)override;
	void Collision(int count)override {};
};