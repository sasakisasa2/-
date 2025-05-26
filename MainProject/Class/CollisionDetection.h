#pragma once
#include"SpriteRender.h"

class CollisionDetection:public SpriteRender
{
private:
public:
	CollisionDetection(){ }
	~CollisionDetection() { }
	void SetDate()override {}
	void UpDate()override {}

	bool Detection(int ID, int ID2);

	void RegisterCollision(SpriteRender* object);
};