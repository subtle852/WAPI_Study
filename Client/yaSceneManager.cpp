#include "yaSceneManager.h"
#include "yaPlayScene.h"

namespace ya
{
	std::vector<Scene*> SceneManager::mScenes = {}; // static ���� �ʱ�ȭ

	void SceneManager::Initialize()
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

	void SceneManager::Update()
	{
		for (Scene* scene : mScenes)
		{
			if (scene == nullptr) continue;
			scene->Update();
		}
	}

	void SceneManager::Render(HDC hdc)
	{
		for (Scene* scene : mScenes)
		{
			if (scene == nullptr) continue;
			scene->Render(hdc);
		}
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
}
