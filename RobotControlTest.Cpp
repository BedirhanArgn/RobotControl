#include "RobotControl.h"
#include "Encryption.h"
#include <iostream>
using namespace std;
void MotionMenu() {
	cout << "Motion Menu" << endl
		<< "1. Move Robot" << endl
		<< "2. Stop Robot" << endl
		<< "3. Turn Left" << endl
		<< "4. Turn Right" << endl
		<< "5. Forward" << endl
		<< "6. Backward" << endl
		<< "7. Quit" << endl;
}
RobotControl *robot;
RobotOperator *robot2;
Encryption *robot3;
int main() {
	robot = new RobotControl;
	robot2 = new RobotOperator;
	robot3 = new Encryption;
	int option;
	string x, y;
	float speed = 0;
	cout << ("Enter your name and surname: ") << endl;
	cin >> x >> y;
	robot2->setName(x);
	robot2->setSurname(y);
	cout << ("Enter your password to connect") << endl;
	cin >> robot->password;
	robot->openAccess(robot->password);
	robot2->print();
	//float distance;
	while (1) {
		MotionMenu();
		cin >> option;
		if (option == 1)
		{
			if (robot->getAccess() == 1)
			{
				cout << "Move Robot:Enter Speed" << endl;
				cin >> speed;
				robot->moveRobot(speed);
			}
		}
		else if (option == 2) {
			if (robot->getAccess() == 1)
			{
				cout << "Stop Robot" << endl;
				robot->stopMove();
			}
		}
		else if (option == 3) {
			if (robot->getAccess() == 1)
			{
				cout << "Turn Left" << endl;
				robot->turnLeft();
			}
		}
		else if (option == 4) {
			if (robot->getAccess() == 1)
			{
				cout << "Turn Right" << endl;
				robot->turnRight();

			}
		}
		else if (option == 5) {
			if (robot->getAccess() == 1)
			{
				cout << "Forward" << endl;
				robot->forward(speed);

			}
		}
		else if (option == 6) {
			if (robot->getAccess() == 1)
			{
				cout << "Backward" << endl;
				robot->backward(speed);

			}
		}
		else if (option == 7) {

			cout << ("Enter your password to disconnect") << endl;
			cin >> robot->password;
			if (robot->password == robot3->decrypt(robot2->getAccessCode()))
			{
				robot->closeAccess(robot->password);
				robot->~RobotControl();
				break;
			}
		}
	}
	system("pause");
}