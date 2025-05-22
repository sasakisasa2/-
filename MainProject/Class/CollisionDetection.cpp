#include "CollisionDetection.h"

void CollisionDetection::SetDate()
{ 
	SetPosition(Vector2(600.0f, 600.0f), EnemyID);
	SetSpriteSize(Vector2(100.0f,100.0f), EnemyID);
}

void CollisionDetection::UpDate()
{
	Vector2 pos = GetPosition(EnemyID);

	Vector2 move = GetPosition(PlayerID) - pos;

	move.Normalize();

	pos += move * speed * DXTK->Time.deltaTime;

	SetPosition(pos, EnemyID);
}
