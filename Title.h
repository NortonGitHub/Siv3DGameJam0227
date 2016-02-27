#pragma once
#include "SceneBase.h"
class Title :
	public SceneBase
{
public:
	Title();
	~Title();

	SceneBase* update() override;
	void draw() override;
};

