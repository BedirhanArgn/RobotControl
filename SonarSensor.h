#pragma once
#include"PioneerRobotAPI.h"
#include<iostream>
#include<string>
using namespace std;
class SonarSensor {
private:
	float ranges[16];
	PioneerRobotAPI* robotAPI;
public:
	/**
	* @brief istenilen indexteki range degerini dondurur.
	* @param index - istenilen index.
	*/
	float getRange(int);
	/**
	* @brief en uzun sensor verisini bulan fonksiyon.
	* @param index- bulunan max degerin hangi indexte oldugunu dondurur.
	*/
	float getMax(int&);
	/**
	* @brief en uzun sensor verisini bulan fonksiyon.
	* @param index- bulunan max degerin hangi indexte oldugunu dondurur.
	*/
	float getMin(int&);
	/**
	* @brief Sensor bilgilerinin guncellenmesi icin gereken fonksiyon.
	* @param ranges - Yeni sensor bilgilerini iceren dizi.
	*/
	void updateSensor(float[]);
	/**
	* @brief Dizi operatoru overloadi.
	* @param i - Istenen index degeri.
	* @return float - Indexte tanimli mesafe degeri.
	*/
	float operator[](int);

};