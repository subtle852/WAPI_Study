#pragma once
#include "yaGameObject.h"
#include "yaImage.h"

namespace ya
{
	class Cuphead : public GameObject
	{
	public: 
		Cuphead();
		~Cuphead();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	private:
		Image* mImage;
	};
}

