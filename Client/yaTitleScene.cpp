#include "yaTitleScene.h"
#include "yaInput.h"
#include "yaSceneManager.h"

ya::TitleScene::TitleScene()
{
}

ya::TitleScene::~TitleScene()
{
}

void ya::TitleScene::Initialize()
{
}

void ya::TitleScene::Update()
{
	if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Play);
	}
}

void ya::TitleScene::Render(HDC hdc)
{
}

void ya::TitleScene::Release()
{
}

void ya::TitleScene::OnEnter()
{
}

void ya::TitleScene::OnExit()
{
}
