#include "Enemy.h"

void Enemy::SetDate(int count)
{ 
	SetPosition(Vector2(600.0f, 600.0f), EnemyID,count);
	SetSpriteSize(XMUINT2(100.0f, 100.0f), EnemyID, count);
}

void Enemy::UpDate(int count)
{
	Vector2 pos = GetPosition(EnemyID,count);

	Vector2 move = GetPosition(PlayerID, count) - pos;

	move.Normalize();

	pos += move * speed * DXTK->Time.deltaTime;

	SetPosition(pos, EnemyID, count);
}

void Enemy::Collision(int count)
{
	SetIsRender(false,EnemyID, count);
}
