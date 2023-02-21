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
		// ��ӹ���� ������
		// ������ ����Ҽ��� 
		// �Ǽ��� �� ������ ��������
		// �ڵ尡 ����������
		//Animation ani
		//Skill skill;
		//Stat stat;

		// ������Ʈ ���
		std::vector<Component*> mComponents;
	};
}
