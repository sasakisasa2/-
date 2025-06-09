#pragma once
#include"GameObject.h"

class Enemy:public GameObject
{
private:

	float speed;

public:
	Enemy():speed(100.0f){ }
	~Enemy()override{Initialize(EnemyID);}
	void SetDate()override;
	void UpDate()override;
	void Collision()override;
};