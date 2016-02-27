#pragma once
#include "CharaBase.h"
#include <Siv3D.hpp>
class Collision
{
public:
	Collision();
	~Collision();

	bool isCollisionDetection(Ellipse a, Rect b);
	bool isCollisionDetectionWithOpp(Ellipse a, Ellipse b);

	Point findAdjustmentCoord(std::string key, Rect a, int wr,int hr);
	Point findAdjustmentCoordOpp(std::string key, Ellipse a, int wr, int hr);
};

