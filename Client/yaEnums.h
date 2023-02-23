#pragma once

enum class eSceneType
{
	Title,
	Play,
	Ending,
	Max,
};

enum class eLayerType // layer 그리는 순서
{
	BG,
	Monster,
	Player,
	Effect,
	UI,
	End,
};

enum class eComponentType
{
	Transform,
	Collider,
	SpriteRenderer,
	Animatior,
	Audio,
	End,
};