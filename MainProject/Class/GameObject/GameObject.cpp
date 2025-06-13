#include "GameObject.h"

// 静的メンバ変数の定義
int                                GameObject::loadCount;
DirectXTK::Sprite                  GameObject::sprite[MAX_ID_NUMBER];
map<int, vector<Vector2>>          GameObject::position;
map<int, vector<Vector2>>          GameObject::imagesCount;
map<int, vector<Vector2>>          GameObject::imagesNumber;
map<int, vector<Color>>            GameObject::color;
map<int, vector<float>>            GameObject::angle;
map<int, vector<SpriteEffects>>    GameObject::spEffect;
map<int, vector<bool>>             GameObject::isRender;
DirectXTK::SpriteBatch             GameObject::spriteBatch;


void GameObject::Initialize()
{
	loadCount = 0;
	for (int id = 0; id < ObjectID::MAX_ID_NUMBER; id++)
	{
		for (int count = 0; count < MAX_OBJECT_NUMBER[id]; count++)
		{
			position    [id][count] = Vector2::Zero;
			imagesCount [id][count] = Vector2::Zero;
			imagesNumber[id][count] = Vector2::One;
			color       [id][count] = Vector4(1.0f, 1.0f, 1.0f, 1.0f);
			angle       [id][count] = 0.0f;
			spEffect    [id][count] = SpriteEffects_None;
			isRender    [id][count] = true;
		}
	}
}

void GameObject::Initialize(int id)
{
	for (int count = 0; count < MAX_OBJECT_NUMBER[id]; count++)
	{
		position    [id][count] = Vector2::Zero;
		imagesCount [id][count] = Vector2::Zero;
		imagesNumber[id][count] = Vector2::One;
		color       [id][count] = Vector4(1.0f, 1.0f, 1.0f, 1.0f);
		angle       [id][count] = 0.0f;
		spEffect    [id][count] = SpriteEffects_None;
		isRender    [id][count] = false;
	}
}

void GameObject::Load()
{
	if (loadCount >= 1) { return; }
	loadCount++;

	auto&& descriptorHeap = DXTK->DescriptorHeap;

	// TODO: Add your device-dependent creation code here.
	descriptorHeap = DirectXTK::CreateDescriptorHeap(DXTK->Device, ObjectID::MAX_ID_NUMBER);

	ResourceUploadBatch resourceUpload(DXTK->Device);
	resourceUpload.Begin();

	for (int ID = 0; ID < ObjectID::MAX_ID_NUMBER; ID++)
	{
		sprite[ID] = DirectXTK::CreateSpriteSRV
		(
			DXTK->Device, ObjectID::SpriteName[ID], resourceUpload,
			DXTK->DescriptorHeap, ID
		);
	}

	RenderTargetState rtState(DXTK->SwapChain.Format, DXTK->SwapChain.DepthFormat);
	SpriteBatchPipelineStateDescription pd(rtState, &CommonStates::NonPremultiplied);

	spriteBatch = DirectXTK::CreateSpriteBatch(DXTK->Device, resourceUpload, pd);
	auto&& viewport = DXTK->SwapChain.Viewport;
	spriteBatch->SetViewport(viewport);

	auto uploadResourcesFinished = resourceUpload.End(DXTK->CommandQueue);
	uploadResourcesFinished.wait();
}

void GameObject::Render()
{

	auto&& heap = DXTK->DescriptorHeap->Heap();
	DXTK->CommandList->SetDescriptorHeaps(1, &heap);

	auto&& spBatch = spriteBatch.get();
	spriteBatch->Begin(DXTK->CommandList);

	for (int ID = 0; ID < ObjectID::MAX_ID_NUMBER; ID++)
	{
		if (!isRender[ID])
			continue;

		Vector2 size;//一枚の大きさ
		size.x = (float)sprite[ID].size.x / imagesNumber[ID].x;
		size.y = (float)sprite[ID].size.y / imagesNumber[ID].y;

		Vector2 minSize;//画像の原点
		minSize.x = size.x * imagesCount[ID].x;
		minSize.y = size.y * imagesCount[ID].y;

		RECT rect;
		rect = RectWH((int)minSize.x, (int)minSize.y, (int)size.x, (int)size.y);

		spBatch->Draw
		(
			sprite[ID].handle, sprite[ID].size,
			position[ID],
			&rect,
			color[ID],
			angle[ID] * Mathf::Deg2Rad,
			size / 2.0f,
			1.0f,
			spEffect[ID]
		);
	}

	spriteBatch->End();
}
