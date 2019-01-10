#include<iostream>
#include"LaserSensor.h"
#include<time.h>
using namespace std;
int main()
{
	srand(time(NULL));
	float test[181];
	int a;
	for (int i = 0; i < 181; i++)
	{
		test[i] = (float)(rand() % 100 + 1);
	}
	LaserSensor lasersensor;
	lasersensor.updateSensor(test);
	cout << lasersensor.getMax(a) << endl;
	cout << lasersensor.getMin(a) << endl;
	cout << lasersensor.getRange(5) << endl;
	system("pause");
}s