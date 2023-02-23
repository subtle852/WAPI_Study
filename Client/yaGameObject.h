#pragma once
#include "yaEntity.h"
#include "yaComponent.h"

namespace ya
{
	class GameObject : public Entity
	{
	public:
		GameObject();
		virtual ~GameObject();
		
		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

		template <typename T>
		T* AddComponent()
		{
			T* comp = new T();
			UINT compType = (UINT)comp->GetType();
			mComponents[compType] = comp;

			return comp;
		}

		template <typename T>
		T* GetComponent()
		{
			for (Component* comp : mComponents)
			{
				if (dynamic_cast<T*>(comp))// 바뀔 수 있는 애들만 바꿔지고 조건이 참으로 반환
				{
					return dynamic_cast<T*>(comp);
				}// RTTI 방식(실행시간에 타입정보를 식별)

				return nullptr;
			}
		}

	private:
	    // HDC mHdc;
		// 상속방식의 단점은
		// 많은걸 상속할수록 
		// 실수를 할 여지가 많아지고
		// 코드가 복잡해진다
		//Animation ani
		//Skill skill;
		//Stat stat;

		// 컴포넌트 방식
		std::vector<Component*> mComponents;
	};
}
