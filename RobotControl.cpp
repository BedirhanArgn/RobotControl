#include "RobotControl.h"

RobotControl::RobotControl()
{
	robot = new RobotOperator(9999);
	robotAPI = new PioneerRobotAPI;
	robotAPI->connect();
}
int RobotControl::getAccess()
{
	return access;
}
void RobotControl::turnLeft()
{	
	robotAPI->turnRobot(PioneerRobotAPI::DIRECTION::left);
	getPose();
}
void RobotControl::turnRight()
{	
	robotAPI->turnRobot(PioneerRobotAPI::DIRECTION::right);
	getPose();
}
void RobotControl::forward(float speed)
{
	robotAPI->moveRobot(speed);
	getPose();
	robotAPI->turnRobot(PioneerRobotAPI::DIRECTION::forward);
}
void RobotControl::moveRobot(float speed)
{
	robotAPI->moveRobot(speed);
}
void RobotControl::print()
{
	print();
}
void RobotControl::backward(float)
{
}
Pose RobotControl::getPose()
{

	position->setX(robotAPI->getX());

	position->setY(robotAPI->getY());

	position->setTh(robotAPI->getTh());
	return *position;
}
void RobotControl::setPose(Pose pose)
{
	robotAPI->setPose(pose.getX(), pose.getY(), pose.getTh());
}

void RobotControl::stopTurn()
{
	robotAPI->stopRobot();
}

void RobotControl::stopMove()
{
	robotAPI->stopRobot();
}

bool RobotControl::clearPath()
{
	Node *node;
	int toplamelemansayisi = 0;
	Node* temp;
	temp = path->gethead();
	node = temp;
	while (temp->next != NULL)
	{
		temp = temp->next;
		toplamelemansayisi++;
	}
	for (int i = 0; i < toplamelemansayisi; i++) {
		path->removePos(i);
	}
	return true;
}

bool RobotControl::addtoPath()
{
	path->addPos(position);
	return true;
}

bool RobotControl::recordPathToFile()
{
	cout << position;

	return true;
}
bool RobotControl::closeAccess(int _value)
{
	RobotOperator robot(_value);
	if (robot.checkAccessCode(_value) == TRUE)
	{
		access = 0;
		return 1;
	}
	else
	{
		access = 1;
		return 0;
	}
}
bool RobotControl::openAccess(int _value)
{
	if (robot->checkAccessCode(_value) == TRUE)
	{
		access = 1;
	}
	else 
		access = 0;
	return 0;
}
RobotControl::~RobotControl()
{
	robotAPI->disconnect();
}
