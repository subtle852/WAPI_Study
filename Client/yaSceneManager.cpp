#include "yaSceneManager.h"
#include "yaPlayScene.h"
#include "yaTitleScene.h"

namespace ya
{
	std::vector<Scene*> SceneManager::mScenes = {}; // static ���� �ʱ�ȭ
	Scene* SceneManager::mActiveScene = nullptr;

	void SceneManager::Initialize()
	{
		mScenes.resize((UINT)eSceneType::Max);

		mScenes[(UINT)eSceneType::Title] = new TitleScene();
		mScenes[(UINT)eSceneType::Play] = new PlayScene();
		//mScenes[(UINT)eSceneType::Play]->SetName(L"PLAYER"); //Entity Ȱ���

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
			if (scene == nullptr) continue;// nullptr�� ��쵵 ������ ����ó��

			delete scene;
			scene = nullptr;
		}
	}
	void SceneManager::LoadScene(eSceneType type)
	{
		// ���� �� �����鼭
		mActiveScene->OnExit();

		// ���ο� �� �����鼭
		mActiveScene = mScenes[(UINT)type];
		mActiveScene->OnEnter();
	}
}
