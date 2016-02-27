#pragma once
#include "SceneBase.h"

#include "Player.h"
#include "Enclosure.h"
#include "Object.h"

class Game :
	public SceneBase
{
public:
	Game();
	~Game();

	SceneBase* update() override;
	void draw() override;

private:
	Player player[2];
	std::map<std::string, Enclosure*> enclosures;
	std::vector<Object*> objects;

};

