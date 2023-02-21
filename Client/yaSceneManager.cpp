#include "yaSceneManager.h"
#include "yaPlayScene.h"

namespace ya
{
	std::vector<Scene*> SceneManager::mScenes = {}; // static 변수 초기화

	void ya::SceneManager::Initialize()
	{
		mScenes.resize((UINT)eSceneType::Max);

		mScenes[(UINT)eSceneType::Play] = new PlayScene();
		// mScenes[(UINT)eSceneType::Play]->SetName(L"PLAYER"); Entity 활용법

		for (Scene* scene : mScenes)
		{
			if (scene == nullptr) continue;
			scene->Initialize();
		}
	}

	void ya::SceneManager::Update()
	{
		for (Scene* scene : mScenes)
		{
			if (scene == nullptr) continue;
			scene->Update();
		}
	}

	void ya::SceneManager::Render(HDC hdc)
	{
		for (Scene* scene : mScenes)
		{
			if (scene == nullptr) continue;
			scene->Render(hdc);
		}
	}

	void ya::SceneManager::Release()
	{
		for (Scene* scene : mScenes)
		{
			if (scene == nullptr) continue;
			scene->Release();
		}
	}
}
