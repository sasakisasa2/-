#pragma once
#include"../GameObject/GameObject.h"
#include<random>

class Enemy:public GameObject
{
private:

	float speed;

public:
	Enemy():speed(100.0f){ }
	~Enemy()override{Initialize(EnemyID);}
	void SetDate  (int count)override;
	void UpDate   (int count)override;
	void Collision(int count)override;
};