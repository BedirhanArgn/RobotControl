#pragma once
#include"PioneerRobotAPI.h"
#include<iostream>
class RangeSensor {
protected:
	float *ranges;
	PioneerRobotAPI* robotAPI;
public:
	RangeSensor();
	virtual float getRange(int) = 0;
	virtual float getMax(int&) = 0;
	virtual float getMin(int&) = 0;
	virtual void updateSensor(float[]) = 0;
	virtual float operator[](int) = 0;
	virtual float getAngle(int) = 0;
	virtual float getClosestRange(float, float, float&) = 0;
};