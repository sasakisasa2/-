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
	ob[BGID]    =new BG();
	ob[PlayerID]=new Player();
	CD.Detection(PlayerID, ob[PlayerID]);
	ob[EnemyID] = new Enemy();
	CD.Detection(EnemyID,  ob[EnemyID]);
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
		ob[i]->SetDate();
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
		if (ob[i])
		{
			ob[i]->UpDate();
		}

		auto&& m = spRen->GetIsRender(i);
		if (m.empty())
		{
			delete ob[i];
			ob[i] = nullptr;
			CD.MapErase(i);
		}
	}
	if (ob[PlayerID]&&ob[EnemyID])
	{
		CD.RegisterCollision(PlayerID, EnemyID);
	}
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
