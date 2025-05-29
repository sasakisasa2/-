#include "CollisionDetection.h"

bool CollisionDetection::Detection(int ID, int ID2)
{
	float ratio = sqrt
	(
		(GetPosition(ID).x - GetPosition(ID2).x) *
		(GetPosition(ID).x - GetPosition(ID2).x) +
		(GetPosition(ID).y - GetPosition(ID2).y) *
		(GetPosition(ID).y - GetPosition(ID2).y)
	);

	if(ratio <= 10.0f)
		return true;
}

void CollisionDetection::Detection(int ID, SpriteRender* ob)
{
	cmap[ID].emplace_back(ob);
}

void CollisionDetection::RegisterCollision(SpriteRender*& object)
{
	delete object;
	object = nullptr;
}

void CollisionDetection::RegisterCollision(int ID1, int ID2)
{
	std::vector<SpriteRender*>& cd1 = cmap[ID1];
	std::vector<SpriteRender*>& cd2 = cmap[ID2];
	for (int i = 0; i < cd1.size(); i++)
	{
		for (int j = 0; j < cd2.size(); j++) 
		{
			if (Detection(ID1, ID2))
			{
				cd1[j]->Collision();
				cd2[j]->Collision();
			}
		}
	}
}
