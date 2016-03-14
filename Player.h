#pragma once
#include "CharaBase.h"
#include "KeyBase.h"
#include"EffectManager.h"

class Player :
	public CharaBase
{
public:
	Player(int n);
	~Player();

	Player* update();
	void draw();

	void drawNormal();
	void drawBroken();

	void setAcceleration(double _x, double _y);

	void setEffectsInit(Point oponentAcce, Vec2 myCenter);

	int getHeightRadius() { return _hr; };
	int getWidthRadius() { return _wr; };

	double getAccelerationX() { return _accelerationX; }
	double getAccelerationY() { return _accelerationY; }

	void reflectingDamageToHP(Point opponent);
	void reflectingDamageToHPWithWall();

	void initPlayer(int n);

	Ellipse getEllipseBody() { return Body; };

	std::string getMovingDirection() { return _direction; }

	bool isHPFallBelowZERO();

private:


	Ellipse Body;
	KeyBase key;

	EffectManager effects;

	void updateResistance();
	void rollDirection();
	void setMovingDirection();

	int frame;

	int num;
	int _hp;

	Font font;	//�e�X�g�p

	std::string _direction;//"right,left,up,down,stop"
};

