#pragma once
#include "yaEntity.h"
#include "yaLayer.h"

namespace ya
{
	class Scene : public Entity
	{
	public: // Scene을 상속받는 TitleScene... 과 같은 클래스 생성
		Scene();
		virtual ~Scene();
		
		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

		void AddGameObject(GameObject* obj, eLayerType layer);

	private:
		std::vector<Layer> mLayers;
	};
}
