#include "Player.h"

void Player::SetDate(int count)
{ 
	SetPosition(Vector2(300.0f, 300.0f), PlayerID,count);
	anime->SetDate(count);
}

void Player::UpDate(int count)
{
	Vector2 pos = GetPosition(PlayerID,count);

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
		((float)GetSprite(PlayerID).size.x / GetImagesNumber(PlayerID,count).x) / 2.0f,
		((float)GetSprite(PlayerID).size.y / GetImagesNumber(PlayerID,count).y) / 2.0f,
		DXTK->SwapChain.Width  - ((float)GetSprite(PlayerID).size.x / GetImagesNumber(PlayerID,count).x) / 2.0f,
		DXTK->SwapChain.Height - ((float)GetSprite(PlayerID).size.y / GetImagesNumber(PlayerID,count).y) / 2.0f
	);

	if (pos.x > border.z)//右端
		pos.x = border.z;
	if (pos.x < border.x)//左端
		pos.x = border.x;
	if (pos.y > border.w)//下端
		pos.y = border.w;
	if (pos.y < border.y)//上端
		pos.y = border.y;

	SetPosition(pos, PlayerID,count);

	anime->UpDate(count);
}

void Player::Collision(int count)
{
	SetIsRender(false, PlayerID,count);
}
