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

void CollisionDetection::RegisterCollision(SpriteRender* object)
{
	delete object;
}
