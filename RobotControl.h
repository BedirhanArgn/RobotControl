#pragma once
#include "Pose.h"
#include "PioneerRobotAPI.h"
#include "RobotOperator.h"
#include "Path.h"
#include"Record.h"
class RobotControl
{
private:
	Pose *position=new Pose;
	Path *path=new Path;
	PioneerRobotAPI *robotAPI=new PioneerRobotAPI;
	Record *record;
	int state;
	int access;
public:
	RobotControl();
	int getAccess();
	void turnLeft();
	void turnRight();
	void forward(float);
	void moveRobot(float);
	void print();
	void backward(float);
	Pose getPose();
	void setPose(Pose);
	void stopTurn();
	void stopMove();
	bool openAccess(int);
	bool closeAccess(int);
	bool clearPath();
	bool addtoPath();
	bool recordPathToFile();
	RobotOperator *robot;
	int password;
	~RobotControl();
};

