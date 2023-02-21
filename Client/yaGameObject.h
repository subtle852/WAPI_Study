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

		void SetPos(Vector2 pos) { mPos = pos; }

	protected:
		Vector2 mPos;

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
