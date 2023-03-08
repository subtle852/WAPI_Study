#include "yaTitleScene.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaCuphead.h"
#include "yaMonster.h"
#include "yaCollisionManager.h"
#include "yaTransform.h"
#include "yaCamera.h"
#include "yaObject.h"

namespace ya
{
	TitleScene::TitleScene()
	{
	}
	TitleScene::~TitleScene()
	{
	}
	void TitleScene::Initialize()
	{
		Cuphead* mCuphead = new Cuphead();
		AddGameObeject(mCuphead, eLayerType::Player);
		//mCuphead->GetComponent<Transform>()->SetPos();
		//Camera::SetTarget(mCuphead);
		object::Instantiate<Monster>(eLayerType::Monster);

		
		//Scene::Initialize();
	}
	void TitleScene::Update()
	{
		Scene::Update();

		if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::Play);
		}

	}
	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void TitleScene::Release()
	{
		Scene::Release();
	}
	void TitleScene::OnEnter()
	{
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
	}
	void TitleScene::OnExit()
	{
	}
}
