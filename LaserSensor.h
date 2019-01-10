#pragma once
#include<iostream>
#include"PioneerRobotAPI.h"
using namespace std;
/**
* @brief Laser mesafe sensörü için veri tutma ve yönetimini saðlar.
*/
class LaserSensor {
private:
	float ranges[181];
	PioneerRobotAPI* robotAPI = new PioneerRobotAPI;
	float min;
	float max;
public:
	float getRange(int);
	void updateSensor(float[]);
	float getMax(int&);
	float getMin(int&);
	float operator[](int);
	float getAngle(int);
	float getClosestRange(float, float, float&);
};