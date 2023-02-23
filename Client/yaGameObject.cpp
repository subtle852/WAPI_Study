#include "yaGameObject.h"
#include "yaTransform.h"

namespace ya
{




	GameObject::GameObject()
	{
		mComponents.resize((UINT)eComponentType::End);

		AddComponent<Transform>();// 게임 오브젝트 만들면 Transform 항상 붙어있게 구성
	}

	GameObject::~GameObject()
	{
		for (Component* comp : mComponents)
		{
			delete comp;
			comp = nullptr;
		}
	}

	void GameObject::Initialize()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr) continue;
			comp->Initialize();
		}
	}

	void GameObject::Update()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr) continue;
			comp->Update();
		}
	}

	void GameObject::Render(HDC hdc)
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr) continue;
			comp->Render(hdc);
		}
	}

	void GameObject::Release()
	{

	}

}
