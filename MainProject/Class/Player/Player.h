#pragma once
#include"../GameObject/GameObject.h"
#include"../Player/Animation/PlayerAnimation.h"

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
	void SetDate  (int count)override;
	void UpDate   (int count)override;
	void Collision(int count)override;
};