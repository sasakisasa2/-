#pragma once
#include"SpriteRender.h"

class Enemy:public SpriteRender
{
private:

	float speed;

public:
	Enemy():speed(100.0f){ }
	~Enemy()override{Initialize(EnemyID);}
	void SetDate()override;
	void UpDate()override;

};