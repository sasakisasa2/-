#pragma once
#include"SpriteRender.h"
#include<map>

class CollisionDetection
{
private:
public:
	CollisionDetection(){ }
	~CollisionDetection() { }

	bool Detection(Vector2 ob1, Vector2 ob2);
	void Detection(int ID, SpriteRender*);

	void RegisterCollision(SpriteRender*& object);
	void RegisterCollision(int ID1, int ID2);

	std::map<int,std::vector<SpriteRender*>> cmap;
};