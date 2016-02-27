#pragma once
class SceneBase
{
public:
	SceneBase();
	~SceneBase();

	virtual SceneBase* update() = 0;
	virtual void draw() = 0;
};

