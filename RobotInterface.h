#pragma once
#include"Pose.h"
class RobotInterface {
private:
	Pose* position;
	int state;
public:
	virtual void turnLeft() = 0;
	virtual void turnRight() = 0;
	virtual void forward(float) = 0;
	virtual void print() = 0;
	virtual void backward(float) = 0;
	virtual Pose getPose() = 0;
	virtual void setPose(Pose) = 0;
	virtual void stopMove() = 0;
	virtual void stopTurn() = 0;
	virtual void updateSensors() = 0;
};