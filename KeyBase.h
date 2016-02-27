#pragma once
class KeyBase
{
public:
	KeyBase();
	~KeyBase();

	void inputKey(double &_acceX,double &_acceY,int playerNum);

	std::string keycode;
private:
	const double acceVal;


	void inputKey1(double &_acceX, double &_acceY);
	void inputKey2(double &_acceX, double &_acceY);

};

