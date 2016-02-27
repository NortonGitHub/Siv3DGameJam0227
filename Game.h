#pragma once
#include "SceneBase.h"
class Game :
	public SceneBase
{
public:
	Game();
	~Game();

	SceneBase* update() override;
	void draw() override;
};

