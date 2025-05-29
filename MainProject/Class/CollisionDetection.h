#pragma once
#include"SpriteRender.h"
#include<map>

class CollisionDetection:public SpriteRender
{
private:
public:
	CollisionDetection(){ }
	~CollisionDetection() { }
	void SetDate()override {}
	void UpDate()override {}

	bool Detection(int ID, int ID2);
	void Detection(int ID, SpriteRender*);

	void RegisterCollision(SpriteRender*& object);
	void RegisterCollision(int ID1, int ID2);

	std::map<int,std::vector<SpriteRender*>> cmap;
};