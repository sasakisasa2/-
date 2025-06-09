#pragma once
#include"GameObject.h"
#include"PlayerAnimation.h"

using namespace DirectX;
using namespace SimpleMath;

class Player:public GameObject
{
private:

	float speed;
	GameObject* anime;

public:
	Player():speed(500.0f){ anime = new PlayerAnimation(); }
	~Player()override { Initialize(PlayerID); }
	void SetDate()override;
	void UpDate()override;
	void Collision()override;
};