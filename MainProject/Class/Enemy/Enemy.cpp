#include "Enemy.h"

void Enemy::SetDate(int count)
{ 
	std::random_device rand_dev; 
	std::mt19937                          random = std::mt19937(rand_dev());
	std::uniform_real_distribution<float> x_pos_range_ = std::uniform_real_distribution<float>(0.0f, 1200.0f);
	std::uniform_real_distribution<float> y_pos_range_ = std::uniform_real_distribution<float>(0.0f, 600.0f);
	SetPosition(Vector2(x_pos_range_(random), y_pos_range_(random)), EnemyID, count);
	SetSpriteSize(XMUINT2(100.0f, 100.0f), EnemyID);
}

void Enemy::UpDate(int count)
{
	Vector2 pos = GetPosition(EnemyID,count);

	Vector2 move = GetPosition(PlayerID, 0) - pos;

	move.Normalize();

	pos += move * speed * DXTK->Time.deltaTime;

	SetPosition(pos, EnemyID, count);
}

void Enemy::Collision(int count)
{
	SetIsRender(false,EnemyID, count);
}
