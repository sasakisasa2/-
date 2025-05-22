#include "Player.h"

void Player::SetDate()
{ 
	SetPosition(Vector2(300.0f, 300.0f), PlayerID);
	anime.SetDate();
}

void Player::UpDate()
{
	Vector2 pos = GetPosition(PlayerID);

	Vector2 move;

	if (InputSystem.Keyboard.isPressed.W)
	{
		move.y -= speed * DXTK->Time.deltaTime;
	}
	if (InputSystem.Keyboard.isPressed.A)
	{
		move.x -= speed * DXTK->Time.deltaTime;
	}
	if (InputSystem.Keyboard.isPressed.S)
	{
		move.y += speed * DXTK->Time.deltaTime;
	}
	if (InputSystem.Keyboard.isPressed.D)
	{
		move.x += speed * DXTK->Time.deltaTime;
	}

	move.Normalize();

	pos += move;

	SetPosition(pos, PlayerID);

	anime.UpDate();
}