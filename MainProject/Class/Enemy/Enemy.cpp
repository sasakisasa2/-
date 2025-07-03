#include "Enemy.h"

void Enemy::SetDate()
{ 
	std::random_device rand_dev; 
	random = std::mt19937(rand_dev());
	std::uniform_real_distribution<float> x_pos_range_ = std::uniform_real_distribution<float>(0.0f, 1200.0f);
	std::uniform_real_distribution<float> y_pos_range_ = std::uniform_real_distribution<float>(0.0f, 600.0f);
	enemyNumber = std::uniform_real_distribution<float>(0.0f, (float)MAX_OBJECT_NUMBER[EnemyID]-0.1f);
	SetSpriteSize(XMUINT2(100.0f, 100.0f), EnemyID);
	for (int i = 0; i < MAX_OBJECT_NUMBER[EnemyID]; i++)
	{
		SetPosition
		(
			Vector2
			(
				(float)DXTK->SwapChain.Width/(float)MAX_OBJECT_NUMBER[EnemyID]*i,
				300
			),
			EnemyID, 
			i
		);
	}
}

void Enemy::UpDate()
{
	for (int i = 0; i < GetIsRender(EnemyID).size(); i++)
	{
		Vector2 pos = GetPosition(EnemyID, i);

		Vector2 move = GetPosition(PlayerID, 0) - pos;

		move.Normalize();

		//pos += move * speed * DXTK->Time.deltaTime;

		SetPosition(pos, EnemyID, i);
	}
	if (InputSystem.Keyboard.isPressed.Space)
	{
		enemyNumber = std::uniform_real_distribution<float>(0.0f, GetIsRender(EnemyID).size());
		int number = (int)enemyNumber(random);
		VectorErase(EnemyID, number);
		return;
	}
}

void Enemy::Collision(int count)
{
	SetIsRender(false,EnemyID, count);
}
