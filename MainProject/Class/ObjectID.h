namespace ObjectID
{
	enum BackGround
	{
		BGID
	};
	enum Character
	{
		PlayerID = BGID+1,
		EnemyID
	};
	enum Effects
	{ };

	static constexpr int MAX_ID_NUMBER = EnemyID + 1;

	static constexpr int MAX_OBJECT_NUMBER[MAX_ID_NUMBER] =
	{
		1,  //BG
		1,  //Player
		100 //Enemy
	};

	static const wchar_t* SpriteName[MAX_ID_NUMBER] = 
	{
		L"BackGround.png",
		L"Player.png",
		L"Enemy.png",
	};
};