#pragma once
#include"GameObject.h"
#include<map>

class CollisionDetection
{
private:
public:
	CollisionDetection(){ }
	~CollisionDetection() { }

	bool Detection(Vector2 ob1, Vector2 ob2);
	void Detection(int ID, GameObject*&);

	void RegisterCollision(int ID1, int ID2);

	std::map<int,std::vector<GameObject*>> cmap;
};