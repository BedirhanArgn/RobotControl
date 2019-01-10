#include "LaserSensor.h"
#include"PioneerRobotAPI.h"
#include<iostream>
using namespace std;
/**
* @brief  i. Indeksine sahip sensorun mesafe bilgisini dondurur.
* @param Index Dizinin index degeri
*/
float LaserSensor::getRange(int index)
{
	robotAPI->getLaserRange(ranges);
	return ranges[index];
}
/**
* @brief  Robota ait guncel sensor mesafe degerlerini, ranges dizisine yukler.
* @param Mesafe degerlerinin tutuldugu dizi
*/
void LaserSensor::updateSensor(float _ranges[])
{
	for (int i = 0; i < 181; i++)
	{
		ranges[i] = _ranges[i];
	}
}
/**
* @brief  Mesafe degerlerinden maksimum olaný dondurur.Bu mesafeye sahip verinin indeksini
*	parantez içindeki deðiþkene dondurur.
* @param Dizinin index degerinin adresi
*/
float LaserSensor::getMax(int &index)
{

	float max;
	max = ranges[0];
	for (int i = 0; i < 181; i++) {
		if (max < ranges[i]) {
			max = ranges[i];
			index = i;

		}
	}
	return max;
}
/**
* @brief  Mesafe degerlerinden minimum olani dondurur.Bu mesafeye sahip verinin indeksini
*	parantez icindeki degiskene dondurur.
* @param Dizinin index degerinin adresi
*/

float LaserSensor::getMin(int &index)
{

	robotAPI->getLaserRange(ranges);
	min = ranges[0];
	cout << robotAPI->getX();
	for (int i = 0; i < 181; i++) {
		if (min > ranges[i]) {
			min = ranges[i];
			index = i;
		}
	}
	return min;
}
/**
* @brief Indeksi verilen sensor degerini dondurur. getRange(i) ile benzer fonksiyonu gercekler.
* @param Dizi indeksi
*/
float LaserSensor::operator[](int i)
{
	return getRange(i);
}
/**
* @brief  Ýndeksi verilen sensorun aci degerini dondurur.
* @param Dizi indeksi
*/
float LaserSensor::getAngle(int index)
{

	return ranges[index];
}
/**
* @brief startAngle ve endAngle acilari arasinda kalan
* mesafelerden en kucuk olaninin acisini angle uzerinde, mesafeyi ise return ile dondurur.
* @param  Baslangic acisi
* @param  Bitis acisi
* @param  Aradaki aci
*/
float LaserSensor::getClosestRange(float startAngle, float endAngle, float &angle)
{

	angle = endAngle - startAngle;
	int counter1 = 0;
	for (int i = 0; i < 181; i++)
	{
		if (ranges[i] == startAngle)
		{
			break;
		}
		counter1++;
	}
	int counter2 = 0;
	for (int i = 0; i < 181; i++)
	{
		if (ranges[i] == endAngle)
		{
			break;
		}
		counter2++;
	}
	float closest = ranges[counter1];
	for (int i = counter1; i < counter2; i++)
	{
		if (ranges[i] < closest)
			closest = ranges[i];
	}
	return closest;
}