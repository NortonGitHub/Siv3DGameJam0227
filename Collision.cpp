#include "Collision.h"



Collision::Collision()
{
}


Collision::~Collision()
{
}

bool Collision::getCollisionDetection(Ellipse a, Rect b)
{
	if (a.intersects(b)) {
		return true;
	}
	return false;
}

