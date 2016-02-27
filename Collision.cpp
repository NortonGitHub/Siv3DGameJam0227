#include "Collision.h"



Collision::Collision()
{
}


Collision::~Collision()
{
}

bool Collision::isCollisionDetection(Ellipse a, Rect b)
{
	if (a.intersects(b)) {
		return true;
		
	}
	return false;
}

bool Collision::isCollisionDetectionWithOpp(Ellipse a, Ellipse b)
{
#if 0
	if (a.intersects(b)){
		return true;
	}
#endif
	return false;
}

Point Collision::findAdjustmentCoord(std::string key, Rect a, int wr,int hr)
{
	Point e(0.0, 0.0);
	if (key == "Up") {
		e.y = a.h + hr;
	}
	if (key == "Bottom") {
		e.y = a.y - hr;
	}
	if (key == "Left") {
		e.x = a.w + wr;
	}
	if (key == "Right") {
		e.x = a.x - wr;
	}
	return e;
}

Point Collision::findAdjustmentCoordOpp(std::string key, Ellipse a, int wr, int hr)
{
	Point e(0.0, 0.0);
	if (key == "Up") {
		e.y = a.y + hr;
	}
	if (key == "Down") {
		e.y = a.y - hr;
	}
	if (key == "Left") {
		e.x = a.y + wr;
	}
	if (key == "Right") {
		e.x = a.x - wr;
	}
	return e;
}

