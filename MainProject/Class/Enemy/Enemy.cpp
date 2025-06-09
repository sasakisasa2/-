#include "Enemy.h"

void Enemy::SetDate()
{ 
	SetPosition(Vector2(600.0f, 600.0f), EnemyID);
	SetSpriteSize(Vector2(100.0f,100.0f), EnemyID);
}

void Enemy::UpDate()
{
	Vector2 pos = GetPosition(EnemyID);

	Vector2 move = GetPosition(PlayerID) - pos;

	move.Normalize();

	pos += move * speed * DXTK->Time.deltaTime;

	SetPosition(pos, EnemyID);
}

void Enemy::Collision()
{
	SetIsRender(false,EnemyID);
}
