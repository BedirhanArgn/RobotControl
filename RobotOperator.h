#include<string>
#include<iostream>
using namespace std;

/*
*@brief Robota eri�im i�in kullan�lan fonksiyon
*@param Isim ve Soyisim robota eri�en kullan�c�n�n bilgilerini tutar
*@param accessCode robotun olu�turulurken ald��� �ifrelenmi� 4 basamakl� bir say�y� tutar
*@param accessState kullan�c�n�n girdi�i say�y�, �ifresi ��z�lm�� accessCode ile k�yaslar
*/

class RobotOperator
{
private:
	string name;
	string surname;
	unsigned int accessCode;
	bool accessState;
	int encryptCode(int _value);
	int decryptCode(int _value);

public:
	RobotOperator(int _accessCode=9999);
	int getAccessCode();
	void setName(string _name);
	string getName();
	void setSurname(string _surname);
	string getSurname();
	void setAccessCode(int _accessCode);
	bool checkAccessCode(int _value);
	void print();

	~RobotOperator();
};

