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
		move.y -= speed * DXTK->Time.deltaTime;
	if (InputSystem.Keyboard.isPressed.A)
		move.x -= speed * DXTK->Time.deltaTime;
	if (InputSystem.Keyboard.isPressed.S)
		move.y += speed * DXTK->Time.deltaTime;
	if (InputSystem.Keyboard.isPressed.D)
		move.x += speed * DXTK->Time.deltaTime;

	move.Normalize();

	pos += move;

	Vector4	border;

	border = Vector4
	(
		((float)GetSprite(PlayerID).size.x / GetImagesNumber(PlayerID).x) / 2.0f,
		((float)GetSprite(PlayerID).size.y / GetImagesNumber(PlayerID).y) / 2.0f,
		DXTK->SwapChain.Width  - ((float)GetSprite(PlayerID).size.x / GetImagesNumber(PlayerID).x) / 2.0f,
		DXTK->SwapChain.Height - ((float)GetSprite(PlayerID).size.y / GetImagesNumber(PlayerID).y) / 2.0f
	);

	if (pos.x > border.z)//右端
		pos.x = border.z;
	if (pos.x < border.x)//左端
		pos.x = border.x;
	if (pos.y > border.w)//下端
		pos.y = border.w;
	if (pos.y < border.y)//上端
		pos.y = border.y;

	SetPosition(pos, PlayerID);

	anime.UpDate();
}