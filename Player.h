#pragma once
#include "CharaBase.h"
#include "KeyBase.h"

class Player :
	public CharaBase
{
public:
	Player();
	~Player();

	void update();
	void draw();

	void setAcceleration(double _x, double _y);

	int getHeightRadius() { return _hr; };
	int getWidthRadius() { return _wr; };

	double getAccelerationX() { return _accelerationX; }
	double getAccelerationY() { return _accelerationY; }

	void initPlayer(int n);

	Ellipse Body;

	std::string getMovingDirection() { return key.keycode; }

private:
	KeyBase key;
	void updateResistance();

	void rollDirection();

	int frame;

	int num;
};

