#include "Player.h"



Player::Player()
{
	_wr = 40;
	_hr = 60;

	_accelerationX = 0.0;
	_accelerationY = 0.0;
	
	color = Palette::White;

	frame = 0;
	
}


Player::~Player()
{
}

void Player::update()
{
	updateResistance();

	_x += _accelerationX;
	_y += _accelerationY;

	Body.x = _x;
	Body.y = _y;

	key.inputKey(_accelerationX, _accelerationY,num);

	rollDirection();

	++frame;
}

void Player::draw()
{
	Body.draw(color);
}

void Player::setAcceleration(double _x, double _y)
{
	_accelerationX = _x;
	_accelerationY = _y;
}

void Player::initPlayer(int n)
{
	num = n;
	_x = (num == 1) ? 52 : 580;
	_y = (num == 1) ? 380 : 82;

	Body.set(_x, _y, _wr / 2, _hr / 2);
}

void Player::updateResistance()
{
	if (_accelerationX != 0.0) {
		if (_accelerationX < 0) {
			_accelerationX += 0.2;
		}
		else {
			_accelerationX -= 0.2;
		}
	}

	if (_accelerationX<0.2&& _accelerationX>-0.2) {
		_accelerationX = 0.0;
	}
	
	if (_accelerationY != 0.0) {
		if (_accelerationY < 0) {
			_accelerationY += 0.2;
		}
		else {
			_accelerationY -= 0.2;
		}
	}

	if (_accelerationY<0.2&& _accelerationY>-0.2) {
		_accelerationY = 0.0;
	}
}

void Player::rollDirection()
{
	
	if (_accelerationY != 0.0) {
		graPeriod = fmod(graPeriod + 20, 360.0);
		double rad = Radians(graPeriod);
		double size = sin(rad);

		double a = (_hr / 2) - size*4;

		Body.setSize(_wr / 2, a);
	}
	else if (_accelerationX != 0.0) {
		graPeriod = fmod(graPeriod + 45, 360.0);
		double rad = Radians(graPeriod);
		double bi = sin(rad);

		Body.y += bi;

	}
}
