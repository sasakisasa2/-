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
	int eraseCount[2]{ 0,0 };
	auto&& cd1 = cmap[ID1];
	auto&& cd2 = cmap[ID2];
	for (int i = 0; i < cd1.size(); i++)
	{
		for (int j = 0; j < cd2.size(); j++) 
		{
			if (Detection(cd1[i]->GetPosition(ID1,i), cd2[j]->GetPosition(ID2,j)))
			{
				eraseCount[0]++;
				eraseCount[1]++;
				cd1[i]->Collision(ID1);
				cd2[j]->Collision(ID2);
			}
		}
	}
}

void CollisionDetection::MapErase(int ID)
{
	cmap.erase(ID);
}
