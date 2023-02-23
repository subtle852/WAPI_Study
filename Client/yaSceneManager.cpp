#include "yaSceneManager.h"
#include "yaPlayScene.h"
#include "yaTitleScene.h"

namespace ya
{
	std::vector<Scene*> SceneManager::mScenes = {}; // static 변수 초기화
	Scene* SceneManager::mActiveScene = nullptr;

	void SceneManager::Initialize()
	{
		mScenes.resize((UINT)eSceneType::Max);

		mScenes[(UINT)eSceneType::Title] = new TitleScene();
		mScenes[(UINT)eSceneType::Play] = new PlayScene();
		//mScenes[(UINT)eSceneType::Play]->SetName(L"PLAYER"); //Entity 활용법

		mActiveScene = mScenes[(UINT)eSceneType::Play];

		for (Scene* scene : mScenes)
		{
			if (scene == nullptr) continue;
			scene->Initialize();
		}
	}

	void SceneManager::Update()
	{
		mActiveScene->Update();
	}

	void SceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
	}

	void SceneManager::Release()
	{
		for (Scene* scene : mScenes)
		{
			if (scene == nullptr) continue;// nullptr인 경우도 있으니 예외처리

			delete scene;
			scene = nullptr;
		}
	}
	void SceneManager::LoadScene(eSceneType type)
	{
		// 현재 씬 나가면서
		mActiveScene->OnExit();

		// 새로운 씬 들어오면서
		mActiveScene = mScenes[(UINT)type];
		mActiveScene->OnEnter();
	}
}
