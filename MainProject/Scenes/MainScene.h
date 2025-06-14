//
// MainScene.h
//

#pragma once

#include "Scene.h"
#include"../Class/BG.h"
#include"../Class/Player.h"
#include"../Class/Enemy.h"
#include"../Class/CollisionDetection.h"
#include"..\Class\SpriteRender.h"

using Microsoft::WRL::ComPtr;
using std::unique_ptr;
using std::make_unique;
using namespace DirectX;

class MainScene final : public Scene {
public:
	MainScene();
	virtual ~MainScene() { Terminate(); }

	MainScene(MainScene&&) = default;
	MainScene& operator= (MainScene&&) = default;

	MainScene(MainScene const&) = delete;
	MainScene& operator= (MainScene const&) = delete;

	// These are the functions you will implement.
	void Start() override;

	//void LoadAssets() override;
	void CreateDeviceDependentResources() override;
	void CreateResources() override;

	void Initialize() override;
	void Terminate() override;

	void OnDeviceLost() override;
	void OnRestartSound() override;

	NextScene Update(const float deltaTime) override;
	void Render() override;

private:
	SpriteRender* ob[MAX_ID_NUMBER];
	SpriteRender* spRen;
	CollisionDetection CD;
};