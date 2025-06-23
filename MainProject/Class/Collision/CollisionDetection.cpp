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

void CollisionDetection::Detection(int ID, GameObject*& ob)
{
	cmap[ID].emplace_back(ob);
}

void CollisionDetection::RegisterCollision(int ID1, int ID2)
{
	auto&& cd1 = cmap[ID1];
	auto&& cd2 = cmap[ID2];
	for (int i = 0; i < MAX_OBJECT_NUMBER[ID1]; i++)
	{
		for (int j = 0; j < MAX_OBJECT_NUMBER[ID2]; j++)
		{
			if (Detection(cd1[0]->GetPosition(ID1,i), cd2[0]->GetPosition(ID2,j)))
			{
				cd1[0]->Collision(i);
				cd2[0]->Collision(j);
			}
		}
	}
}

void CollisionDetection::MapErase(int ID)
{
	cmap.erase(ID);
}
