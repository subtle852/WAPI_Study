#include "yaPlayScene.h"
#include "yaCuphead.h"

ya::PlayScene::PlayScene()
{
}

ya::PlayScene::~PlayScene()
{
}

void ya::PlayScene::Initialize()
{
	//for (size_t i = 0; i < 5000; i++)
	{
		Cuphead* cuphead = new Cuphead();
		// cuphead->SetPos(Vector2{0.0f, 0.0f + i});
		cuphead->SetName(L"Player");
		AddGameObject(cuphead, eLayerType::Player);
	}

	Scene::Initialize();
}

void ya::PlayScene::Update()
{
	Scene::Update();
}

void ya::PlayScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void ya::PlayScene::Release()
{
	Scene::Release();
}
