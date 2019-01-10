#include<string>
#include<iostream>
using namespace std;

/*
*@brief Robota eriþim için kullanýlan fonksiyon
*@param Isim ve Soyisim robota eriþen kullanýcýnýn bilgilerini tutar
*@param accessCode robotun oluþturulurken aldýðý þifrelenmiþ 4 basamaklý bir sayýyý tutar
*@param accessState kullanýcýnýn girdiði sayýyý, þifresi çözülmüþ accessCode ile kýyaslar
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

