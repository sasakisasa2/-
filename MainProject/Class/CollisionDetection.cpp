#include "CollisionDetection.h"

bool CollisionDetection::Detection(Vector2 ob1, Vector2 ob2)
{
	float ratio = sqrt
	(
		(ob1.x - ob2.x) * (ob1.x - ob2.x) +
		(ob1.y - ob2.y) * (ob1.y - ob2.y)
	);

	if (ratio <= 10.0f)
		return true;

	return false;
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
			if (Detection(cd1[i]->GetPosition(ID1), cd2[j]->GetPosition(ID2)))
			{
				cd1[i]->Collision();
				cd2[j]->Collision();
			}
		}
	}
}
