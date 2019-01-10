#include<iostream>
#include"SonarSensor.h"
using namespace std;

int main() {

	SonarSensor *test = new SonarSensor;
	float a[16] = { 1.2, 3.5, 1.6, 6.2, 2.4, 8.9, 123.5, 632.5, 187.7, 843.5, 321.5, 877.8, 767.4, 463.1, 123.4,5.2 };
	int index;
	float max;
	float min;
	float get;

	test->updateSensor(a);
	max = test->getMax(index);
	min = test->getMin(index);
	get = test->getRange(index);

	cout << max << " " << min << " " << get << endl;




	system("pause");
}