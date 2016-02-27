#pragma once
#include "SceneBase.h"

#include "Player.h"
#include "Enclosure.h"

class Game :
	public SceneBase
{
public:
	Game();
	~Game();

	SceneBase* update() override;
	void draw() override;

private:
	Player player;
	std::vector<Enclosure*> enclosures;
};

