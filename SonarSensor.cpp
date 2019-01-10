#include<iostream>
#include"PioneerRobotAPI.h"
#include"SonarSensor.h"
using namespace std;
float SonarSensor::getRange(int index)
{
	return ranges[index];
}
float SonarSensor::getMax(int& index)
{
	float max = ranges[0];
	int indexdepo = 0;
	for (int i = 0; i < 16; i++)
	{
		if (ranges[i] > max) {
			max = ranges[i];
			indexdepo = i;
		}
	}
	index = indexdepo;
	return max;
}
float SonarSensor::getMin(int& index)
{
	float min = ranges[0];
	int indexdepo = 0;
	for (int i = 0; i < 16; i++)
	{
		if (ranges[i] < min) {
			min = ranges[i];
			indexdepo = i;
		}
	}
	index = indexdepo;
	return min;
}
void SonarSensor::updateSensor(float ranges[])
{
	for (int i = 0; i < 16; i++)
	{
		this->ranges[i] = ranges[i];
	}
}
float SonarSensor::operator[](int i)
{
	return ranges[i];
}
