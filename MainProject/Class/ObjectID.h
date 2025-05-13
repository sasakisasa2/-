namespace ObjectID
{
	enum BackGround
	{
		BackGroundForest
	};
	enum Character
	{
		Player = BackGroundForest+1,
		Enemy
	};
	enum Effects
	{
		PlayerEffect = Enemy + 1
	};

	static constexpr int MAX_ID_NUMBER = PlayerEffect + 1;

	static const wchar_t* SpriteName[MAX_ID_NUMBER] = 
	{
		L"BackGround.png",
		L"Player.png",
		L"Enemy.png",
		L"PlayerEffect.png"
	};
};