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
	{
		PlayerEffectID = Enemy + 1
	};

	static constexpr int MAX_ID_NUMBER = PlayerEffectID + 1;

	static const wchar_t* SpriteName[MAX_ID_NUMBER] = 
	{
		L"BackGround.png",
		L"Player.png",
		L"Enemy.png",
		L"PlayerEffect.png"
	};
};