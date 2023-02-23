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

		// static���� ����� static �Լ� �ȿ��� ����� �����ϰ�
		// ��� �Լ��� static�� ���� ������ ��������ó�� ��𼭵� ���ٰ����ϰ� �ϱ������̰�
		// ������ Ŭ������ ������� ��ü�� ���� ��(�޸� �Ҵ����� �ʾ���)�� Ư¡�̴�
		// ��ǻ� Ŭ������ ������ �� �������� ������? public, private�� �ٿ��� ����������?
		// �׷��� SceneManager, Time ���� ���� ��� �Լ��� ������ static �� �ٿ�������?
		// �̷��� �س����� ��𼭵� �� ������ϸ� include���ָ�, SceneManager::Initialize() �̷��� ��밡�� ����?
		// �׸��� static�� ���� Ŭ������ �����ڿ� �Ҹ��ڴ� �������� �����ִ°� ������

		// �̱������� ���� ���� �ִ�
		// ���� ��ü�� ������ִ� �����̸�
		// �ڵ尡 �����غ��̴� ������
		// �̱������� ���� Ŭ������ �Ҹ��ڰ� �����찡 ����� ���� ȣ���� �Ǵٺ���
		// ���� ���������� �̱������� ������� ���� ��ü���� �Ҹ��� ȣ�� ������ �ľ��ϱ� ����ٴ� ������ �ִ�
		// ���� �̱��� �Ǵн��� ���� ���� �̿��ϸ� ������ �غ��� �� �ֱ��ѵ�...�� �������
	};
}
