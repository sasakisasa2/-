#include "SpriteRender.h"

// 静的メンバ変数の定義
int     SpriteRender::loadCount;
DirectXTK::Sprite SpriteRender::sprite[MAX_ID_NUMBER];
Vector2 SpriteRender::position    [MAX_ID_NUMBER];
Vector2 SpriteRender::imagesCount [MAX_ID_NUMBER];
Vector2 SpriteRender::imagesNumber[MAX_ID_NUMBER];
Color   SpriteRender::color       [MAX_ID_NUMBER];
float   SpriteRender::angle       [MAX_ID_NUMBER];
SpriteEffects SpriteRender::spEffect[MAX_ID_NUMBER];
bool    SpriteRender::isRender    [MAX_ID_NUMBER];
DirectXTK::SpriteBatch SpriteRender::spriteBatch;


void SpriteRender::Initialize()
{
	loadCount = 0;
	for (int ID = 0; ID < ObjectID::MAX_ID_NUMBER; ID++)
	{
		position[ID]     = Vector2::Zero;
		imagesCount[ID]  = Vector2::Zero;
		imagesNumber[ID] = Vector2::One;
		color[ID]		 = Vector4(1.0f, 1.0f, 1.0f, 1.0f);
		angle[ID]        = 0.0f;
		spEffect[ID]     = SpriteEffects_None;
		isRender[ID]     = true;
	}
}

void SpriteRender::Initialize(int ID)
{
	position[ID]     = Vector2::Zero;
	imagesCount[ID]  = Vector2::Zero;
	imagesNumber[ID] = Vector2::One;
	color[ID]        = Vector4(1.0f, 1.0f, 1.0f, 1.0f);
	angle[ID]        = 0.0f;
	spEffect[ID]     = SpriteEffects_None;
	isRender[ID]     = false;
}

void SpriteRender::Load()
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

void SpriteRender::Render()
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
