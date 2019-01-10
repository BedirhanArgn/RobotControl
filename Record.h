#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"Pose.h"
using namespace std;
class Record {
	/**
	* @brief Verileri dosyadan alýr.
	* @param _file - veri alinacak dosya.
	*/
	friend istream &operator >> (istream &input, Record&_record) {

		_record.openFile();
		float get;
		input >> get;
		_record.pose.setX(get);
		input >> get;
		_record.pose.setY(get);
		input >> get;
		_record.pose.setTh(get);
		_record.closeFile();
		return input;
	}
	/**
	* @brief  Verileri dosyaya yazar.
	* @param _file - veri yazilacak dosya.
	*/
	friend ostream &operator<<(ostream &output, Record&_record) {
		_record.openFile();
		output << _record.pose.getX() << _record.pose.getY() << _record.pose.getTh() << endl;
		return output;
	}
private:
	fstream file;
	string filename;
	int count = 0;
	Pose pose;
public:
	Record();
	/**
	* @brief  dosya acan fonksiyon
	*/
	bool openFile();
	/**
	* @brief  dosya kapatan fonksiyon
	*/
	bool closeFile();
	string data;
	/**
	* @brief  dosya adini degistiren fonksiyon
	*/
	void setFileName(string);
	/**
	* @brief  dosyadan veri okuyan fonksiyon
	*/
	string readLine();
	/**
	* @brief  dosyaya veri yazan fonksiyon
	*/
	bool writeLine(string);

	void setPose(Pose _pose);

	Pose getPose();

	~Record();
};
