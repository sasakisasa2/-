namespace ObjectID
{
	enum BackGround
	{
		BackGroundForest
	};
	enum Character
	{
		PlayerID = BackGroundForest+1,
		EnemyID
	};
	enum Effects
	{ };

	static constexpr int MAX_ID_NUMBER = EnemyID + 1;

	static const wchar_t* SpriteName[MAX_ID_NUMBER] = 
	{
		L"BackGround.png",
		L"Player.png",
		L"Enemy.png",
	};
};