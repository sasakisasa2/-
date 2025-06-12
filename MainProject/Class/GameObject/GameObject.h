#pragma once

#include"../MainProject/Base/pch.h"
#include"../MainProject/Base/dxtk.h"
#include"vector"
#include"map"

using namespace std;
using namespace DirectX;
using namespace SimpleMath;
using namespace ObjectID;

class GameObject
{	
private:
	static int loadCount;

	static map<int, vector<DirectXTK::Sprite>> sprite;
	static map<int, vector<Vector2>> position;
	static map<int, vector<Vector2>> imagesCount;
	static map<int, vector<Vector2>> imagesNumber;
	static map<int, vector<Color>>   color;
	static map<int, vector<float>>   angle;
	static map<int, vector<SpriteEffects>> spEffect;
	static map<int, vector<bool>>    isRender;

	void Initialize();
	static DirectXTK::SpriteBatch spriteBatch;

protected:

	//子クラス初期化用関数
	static void Initialize(int ID);

public:

#pragma region Getter関数

	/// <summary>
	/// mapのvalueがvector型の為、vector用の要素数が引数として必要
	/// </summary>
	/// <param name="ID">key</param>
	/// <param name="count">value</param>
	static DirectXTK::Sprite const GetSprite  (int ID, int count) { return sprite      [ID][count];	}
	static Vector2       const GetPosition    (int ID, int count) { return position    [ID][count]; }
	static Vector2       const GetImagesCount (int ID, int count) { return imagesCount [ID][count]; }
	static Vector2       const GetImagesNumber(int ID, int count) { return imagesNumber[ID][count]; }
	static Color         const GetColor       (int ID, int count) { return color       [ID][count]; }
	static float         const GetAngle       (int ID, int count) { return angle       [ID][count]; }
	static SpriteEffects const GetSpEffect    (int ID, int count) { return spEffect    [ID][count]; }
	static bool          const GetIsRender    (int ID, int count) { return isRender    [ID][count]; }

#pragma endregion

#pragma region Setter関数

	static void SetSpriteSize(XMUINT2 setSize, int ID, int count)
	{
		sprite[ID][count].size.x = setSize.x;
		sprite[ID][count].size.y = setSize.y;
	}
	static void SetPosition    (Vector2 setPos,   int ID, int count)       { position    [ID][count] = setPos;    }
	static void SetImagesCount (Vector2 setCount, int ID, int count)       { imagesCount [ID][count] = setCount;  }
	static void SetImagesNumber(Vector2 setNumber,int ID, int count)       { imagesNumber[ID][count] = setNumber; }
	static void SetColor       (Color   setColor, int ID, int count)       { color       [ID][count] = setColor;  }
	static void SetAngle       (float   setAngle, int ID, int count)       { angle       [ID][count] = setAngle;  }
	static void SetSpEffect    (SpriteEffects setEffect, int ID, int count){ spEffect    [ID][count] = setEffect; }
	static void SetIsRender    (bool    setIsRen, int ID, int count)       { isRender    [ID][count] = setIsRen;  }

#pragma endregion

    GameObject() { Initialize(); }
	virtual ~GameObject(){ }

	static void Load();
	virtual void SetDate()   = 0;
	virtual void UpDate()    = 0;
	virtual void Collision() = 0;
	static void Render();
};