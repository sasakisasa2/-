#pragma once
#include"SpriteRender.h"

class CollisionDetecte:public SpriteRender
{
private:

	float speed;

public:
	Enemy():speed(100.0f){ }
	~Enemy() { Initialize(EnemyID); }
	void SetDate()override;
	void UpDate()override;

};