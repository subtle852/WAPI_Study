#include "yaPlayScene.h"
#include "yaCuphead.h"
#include "yaInput.h"
#include "yaSceneManager.h"

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
		mCuphead = new Cuphead();
		// cuphead->SetPos(Vector2{0.0f, 0.0f + i});
		mCuphead->SetName(L"Player");
		AddGameObject(mCuphead, eLayerType::Player);
	}

	Scene::Initialize();
}

void ya::PlayScene::Update()
{
	if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Title);
	}

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

void ya::PlayScene::OnEnter()
{
}

void ya::PlayScene::OnExit()
{
	// OnExit할 때 이동이라던가 여러가지 요소들을 초기화 시키러면 여기서 이렇게 해줘야 하고 
	// 그렇지 않다면 Initialize에 그 객체들을 만들어 줘야함
	// mCuphead->SetPos(Vector2{ 0.0f, 0.0f });
}
