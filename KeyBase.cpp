#include <Siv3D.hpp>
#include "KeyBase.h"


KeyBase::KeyBase()
	: acceVal(4.0)
{
	keycode = "";
}


KeyBase::~KeyBase()
{
}

void KeyBase::inputKey(double & _acceX, double & _acceY, int playerNum)
{
	(playerNum == 1) ? inputKey1(_acceX, _acceY) : inputKey2(_acceX, _acceY);
}

void KeyBase::inputKey1(double & _acceX, double & _acceY)
{
	if (Input::AnyKeyClicked) {
		if (Input::KeyW.clicked) {
			keycode = "Up";
			_acceY -= acceVal;
			_acceX = 0.0;
		}
		else if (Input::KeyS.clicked) {
			keycode = "Down";
			_acceY += acceVal;
			_acceX = 0.0;
		}
		else if (Input::KeyA.clicked) {
			keycode = "Left";
			_acceX -= acceVal;
			_acceY = 0.0;
		}
		else if (Input::KeyD.clicked) {
			keycode = "Right";
			_acceX += acceVal;
			_acceY = 0.0;
		}
	}
}

void KeyBase::inputKey2(double & _acceX, double & _acceY)
{
	if (Input::AnyKeyClicked) {
		if (Input::KeyUp.clicked) {
			keycode = "Up";
			_acceY -= acceVal;
			_acceX = 0.0;
		}
		else if (Input::KeyDown.clicked) {
			keycode = "Down";
			_acceY += acceVal;
			_acceX = 0.0;
		}
		else if (Input::KeyLeft.clicked) {
			keycode = "Left";
			_acceX -= acceVal;
			_acceY = 0.0;
		}
		else if (Input::KeyRight.clicked) {
			keycode = "Right";
			_acceX += acceVal;
			_acceY = 0.0;
		}
	}
}
