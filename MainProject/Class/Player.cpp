#include "Player.h"

void Player::SetDate()
{ 
	SetPosition(Vector2(300.0f, 300.0f), PlayerID);
	anime.SetDate();
}

void Player::UpDate()
{
	Vector2 pos = GetPosition(PlayerID);
	anime.UpDate();
}