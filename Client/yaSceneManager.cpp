#include "yaSceneManager.h"
#include "yaPlayScene.h"

namespace ya
{
	std::vector<Scene*> SceneManager::mScenes = {}; // static ���� �ʱ�ȭ

	void ya::SceneManager::Initialize()
	{
		mScenes.resize((UINT)eSceneType::Max);

		mScenes[(UINT)eSceneType::Play] = new PlayScene();
		// mScenes[(UINT)eSceneType::Play]->SetName(L"PLAYER"); Entity Ȱ���

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
