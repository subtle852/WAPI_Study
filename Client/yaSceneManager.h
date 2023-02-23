#pragma once
#include "yaScene.h"



namespace ya
{
	class SceneManager
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);
		static void Release();

		static void LoadScene(eSceneType type);

	private:
		static std::vector<Scene*> mScenes;
		static Scene* mActiveScene;

		// static으로 해줘야 static 함수 안에서 사용이 가능하고
		// 멤버 함수에 static을 붙인 이유는 전역변수처럼 어디서든 접근가능하게 하기위함이고
		// 실제로 클래스가 만들어진 객체가 없는 것(메모리 할당하지 않았음)이 특징이다
		// 사실상 클래스긴 하지만 다 전역변수 급이쥬? public, private을 붙여준 전역변수쥬?
		// 그래서 SceneManager, Time 같은 것은 멤버 함수와 변수에 static 다 붙여져있쥬?
		// 이렇게 해놓으면 어디서든 그 헤더파일만 include해주면, SceneManager::Initialize() 이렇게 사용가능 하쥬?
		// 그리고 static을 붙인 클래스의 생성자와 소멸자는 못쓰도록 막아주는게 안전함

		// 싱글톤으로 만들 수도 있다
		// 정적 객체를 만들어주는 개념이며
		// 코드가 복잡해보이는 단점과
		// 싱글톤으로 만든 클래스의 소멸자가 윈도우가 종료될 때에 호출이 되다보니
		// 여러 전역변수와 싱글톤으로 만들어진 정적 객체와의 소멸자 호출 순서를 파악하기 힘들다는 단점이 있다
		// 물론 싱글톤 피닉스와 같은 것을 이용하면 단점을 극복할 수 있긴한데...네 여기까지
	};
}
