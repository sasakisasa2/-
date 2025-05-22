#pragma once
#include"SpriteRender.h"

class CollisionDetection:public SpriteRender
{
private:
public:
	CollisionDetection(){ }
	~CollisionDetection() { Initialize(EnemyID); }
	void SetDate()override;
	void UpDate()override;

	void RegisterCollision(SpriteRender* object);
};