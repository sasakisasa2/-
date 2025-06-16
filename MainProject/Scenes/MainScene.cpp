//
// MainScene.cpp
//

#include "..\Base\pch.h"
#include "..\Base\dxtk.h"
#include "SceneFactory.h"

#ifdef _DEBUG
#pragma warning(disable : 4189)
#endif

using namespace SimpleMath;

// Initialize member variables.
MainScene::MainScene():isDelete()
{
	spRen = new Player();
	ob[BGID]    .emplace_back(new BG());
	ob[PlayerID].emplace_back(new Player());
	CD.Detection(PlayerID, ob[PlayerID][0]);
	for (int count = 0; count < MAX_OBJECT_NUMBER[EnemyID]; count++)
	{
		ob[EnemyID].emplace_back(new Enemy());
		CD.Detection(EnemyID,  ob[EnemyID][count]);
	}
}

// Start is called after the scene is created.
void MainScene::Start()
{
	LoadAssets();
	Initialize();
}

// Load resources.
//void MainScene::LoadAssets()
//{
//	CreateDeviceDependentResources();
//	CreateResources();
//}

// Allocate memory the Direct3D and Direct2D resources.
// These are the resources that depend on the device.
void MainScene::CreateDeviceDependentResources()
{
	spRen->Load();
}

// Create independent resources.
void MainScene::CreateResources()
{

}

// Initialize a variable and audio resources.
void MainScene::Initialize()
{
	for (int i = 0; i < MAX_ID_NUMBER; i++)
	{
		for (int count = 0; count < MAX_OBJECT_NUMBER[i]; count++)
		{
			ob[i][count]->SetDate(count);
		}
	}
}

// Releasing resources required for termination.
void MainScene::Terminate()
{
	// TODO: Add a sound instance reset.
	DXTK->Audio.Engine->Suspend();



	DXTK->Audio.ResetEngine();
	DXTK->WaitForGpu();

	// TODO: Add your Termination logic here.
	DXTK->DescriptorHeap.release();


}

// Direct3D resource cleanup.
void MainScene::OnDeviceLost()
{

}

// Restart any looped sounds here
void MainScene::OnRestartSound()
{

}

// Updates the scene.
NextScene MainScene::Update(const float deltaTime)
{
	// If you use 'deltaTime', remove it.
	UNREFERENCED_PARAMETER(deltaTime);

	// TODO: Add your game logic here.
	for (int i = 0; i < MAX_ID_NUMBER; i++)
	{
		if (ob[i].empty())
			continue;

		int deleteCount = 0;
		for (int count = 0; count < MAX_OBJECT_NUMBER[i]; count++)
		{
			if (ob[i][count])
			{
				if (!spRen->GetIsRender(i,count))
				{
					delete ob[i][count];
					ob[i][count] = nullptr;
					continue;
				}
				ob[i][count]->UpDate(count);
			}
			else
			{
				deleteCount++;
			}
		}
		if (deleteCount == MAX_OBJECT_NUMBER[i]&& !isDelete[i])
		{
			CD.MapErase(i);
			ob.erase(i);
			isDelete[i] = true;
		}
	}

	if (!ob[PlayerID].empty() && !ob[EnemyID].empty())
		CD.RegisterCollision(PlayerID, EnemyID);

	return NextScene::Continue;
}

// Draws the scene.
void MainScene::Render()
{
	// TODO: Add your rendering code here.
	DXTK->Command.Reset();
	DXTK->Command.RTSetupAndClear(Colors::CornflowerBlue);


	spRen->Render();

	//backGround.Render(spriteBatch);

	DXTK->EndScene();
}
