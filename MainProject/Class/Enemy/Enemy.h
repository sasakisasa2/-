#pragma once
#include"../GameObject/GameObject.h"
#include<random>

class Enemy:public GameObject
{
private:

	float speed;
	std::mt19937 random;
	std::uniform_real_distribution<float> enemyNumber;

public:
	Enemy():speed(100.0f){ }
	~Enemy()override{Initialize(EnemyID);}
	void SetDate  ()override;
	void UpDate   ()override;
	void Collision(int count)override;
};