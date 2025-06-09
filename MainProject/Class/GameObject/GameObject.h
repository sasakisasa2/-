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
	/// mapのvalueがvector型の為、vector用の要素数が必要
	/// </summary>
	/// <param name="ID">key</param>
	/// <param name="count">value</param>
	static DirectXTK::Sprite const GetSprite  (int ID, int count) { return sprite[ID][count];	    }
	static Vector2       const GetPosition    (int ID, int count) { return position[ID][count];     }
	static Vector2       const GetImagesCount (int ID, int count) { return imagesCount[ID][count];  }
	static Vector2       const GetImagesNumber(int ID, int count) { return imagesNumber[ID][count]; }
	static Color         const GetColor       (int ID, int count) { return color[ID][count];        }
	static float         const GetAngle       (int ID, int count) { return angle[ID][count];        }
	static SpriteEffects const GetSpEffect    (int ID, int count) { return spEffect[ID][count];     }

#pragma endregion

#pragma region Setter関数

	static void SetSpriteSize(Vector2 setSize, int ID)
	{
		sprite[ID].size.x = setSize.x;
		sprite[ID].size.y = setSize.y;
	}
	static void SetPosition    (Vector2 setPos, int ID)          { position[ID] = setPos;        }
	static void SetImagesCount (Vector2 setCount, int ID)        { imagesCount[ID] = setCount;   }
	static void SetImagesNumber(Vector2 setNumber, int ID)       { imagesNumber[ID] = setNumber; }
	static void SetColor       (Color   setColor, int ID)        { color[ID] = setColor;         }
	static void SetAngle       (float   setAngle, int ID)        { angle[ID] = setAngle;         }
	static void SetSpEffect    (SpriteEffects setEffect, int ID) { spEffect[ID] = setEffect;     }
	static void SetIsRender    (bool    setIsRen, int ID)        { isRender[ID] = setIsRen;      }

#pragma endregion

    GameObject() { Initialize(); }
	virtual ~GameObject(){ }

	static void Load();
	virtual void SetDate()   = 0;
	virtual void UpDate()    = 0;
	virtual void Collision() = 0;
	static void Render();
	static bool const GetIsRender(int ID) { return isRender[ID]; }
	
};