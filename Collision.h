#pragma once
#include "CharaBase.h"
#include <Siv3D.hpp>
class Collision
{
public:
	Collision();
	~Collision();

	bool getCollisionDetection(Ellipse a, Rect b);

};

