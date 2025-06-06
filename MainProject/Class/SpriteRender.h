#pragma once

#include"..\Base\pch.h"
#include"..\Base\dxtk.h"
#include"vector"

using namespace DirectX;
using namespace SimpleMath;
using namespace ObjectID;

class SpriteRender
{	
private:
	static int loadCount;

	static DirectXTK::Sprite sprite  [MAX_ID_NUMBER];
	static Vector2       position    [MAX_ID_NUMBER];
	static Vector2       imagesCount [MAX_ID_NUMBER];
	static Vector2       imagesNumber[MAX_ID_NUMBER];
	static Color         color       [MAX_ID_NUMBER];
	static float         angle       [MAX_ID_NUMBER];
	static SpriteEffects spEffect    [MAX_ID_NUMBER];
	static bool          isRender	 [MAX_ID_NUMBER];

	void Initialize();
	static DirectXTK::SpriteBatch spriteBatch;

protected:

	//子クラス初期化用関数
	static void Initialize(int ID);

public:

#pragma region Getter関数

	static DirectXTK::Sprite const GetSprite  (int ID) { return sprite[ID];       }
	static Vector2       const GetPosition    (int ID) { return position[ID];     }
	static Vector2       const GetImagesCount (int ID) { return imagesCount[ID];  }
	static Vector2       const GetImagesNumber(int ID) { return imagesNumber[ID]; }
	static Color         const GetColor       (int ID) { return color[ID];        }
	static float         const GetAngle       (int ID) { return angle[ID];        }
	static SpriteEffects const GetSpEffect    (int ID) { return spEffect[ID];     }

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

    SpriteRender() { Initialize(); }
	virtual ~SpriteRender(){ }

	static void Load();
	virtual void SetDate()   = 0;
	virtual void UpDate()    = 0;
	virtual void Collision() = 0;
	static void Render();
	static bool const GetIsRender(int ID) { return isRender[ID]; }
	
};