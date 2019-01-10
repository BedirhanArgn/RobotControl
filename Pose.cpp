#include "Pose.h"

#include <iostream>
using namespace std;
Pose::Pose()
{
}

float Pose::getX()
{
	return x;
}

void Pose::setX(float _x)
{
	x = _x;
}

float Pose::getY()
{
	return y;
}

void Pose::setY(float _y)
{
	y = _y;
}

void Pose::setTh(float _th)
{
	th = _th;
}

float Pose::getTh()
{
	return th;
}

bool Pose::operator==(const Pose& other)
{
	if (x != other.x || y != other.y)
		return false;
	else
		return true;

}

Pose Pose::operator+(const Pose &other)
{
	Pose tmp;
	tmp.x = x + other.x;
	tmp.y = y + other.y;
	return tmp;
}

Pose Pose::operator-(const Pose &other)
{
	Pose tmp;
	tmp.x = x - other.x;
	tmp.y = y - other.y;
	return tmp;
}

Pose & Pose::operator-=(const Pose &other)
{
	// TODO: insert return statement here
	Pose tmp;
	x -= other.x;
	y -= other.y;
	tmp.x = x;
	tmp.y = y;
	return tmp;

}

Pose & Pose::operator+=(const Pose &other)
{
	// TODO: insert return statement here
	Pose tmp;
	x += other.x;
	y += other.y;
	tmp.x = x;
	tmp.y = y;
	return tmp;
}

bool Pose::operator<(const Pose &other)
{
	if (x < other.x || y < other.y)
		return false;
	else
		return true;
}

void Pose::getPose(float & _x, float & _y, float & _th)
{
	cout << _x << "   " << _y << "   " << _th;
}

void Pose::setPose(float _x, float _y, float _th)
{
	x = _x;
	y = _y;
	th = _th;
}

float Pose::findDistanceTo(Pose other)
{
	
	return 0.0f;
}

float Pose::findAngleTo(Pose)
{
	return 0.0f;
}


Pose::~Pose()
{
}
