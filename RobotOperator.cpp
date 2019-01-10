#include "Encryption.h"
#include "RobotControl.h"


/// Robot olu�turulurken girilen 4 basamakl� say�y� �ifrelemede kullan�l�r.
/// int de�er d�nd�r�r

int RobotOperator::encryptCode(int _value)
{
	Encryption tool;
	return tool.encrypt(_value);
}
/// Robota eri�im sa�lanmaya �al���ld���nda �ifrelenmi� eri�im kodunu ��z�p kullan�c�n�n girdi�i say�yla k�yaslanabilir hale getirmek i�in kullan�l�r
///int de�er d�nd�r�r
int RobotOperator::decryptCode(int _value)
{
	Encryption tool;
	return tool.decrypt(_value);
}
/// Constructor fonksiyon, olu�turulurken robota eri�im i�in 4 basamakl� int bir say� al�r
RobotOperator::RobotOperator(int _accessCode)
{
	setAccessCode(_accessCode);
}
/// Private tan�mlanan eri�im kodunu �a��rmada kullan�l�r
int RobotOperator::getAccessCode()
{
	return accessCode;
}
/// Robot olu�turulurken girilen 4 basamakl� int say�y� �ifrelemeye yarar
void RobotOperator::setAccessCode(int _accessCode)
{
	accessCode = encryptCode(_accessCode);
}
/// Robota eri�im i�in kullan�c� bilgilerinin al�nmas�nda kullan�l�r
void RobotOperator::setName(string _name)
{
	name = _name;
}
string RobotOperator::getName()
{
	return name;
}
/// Robota eri�im i�in kullan�c� bilgilerinin al�nmas�nda kullan�l�r
void RobotOperator::setSurname(string _surname)
{
	surname = _surname;
}
string RobotOperator::getSurname()
{
	return surname;
}
/// Robota eri�im i�in girilen 4 basamakl� say�y� eri�im koduyla k�yaslar
/// K�yaslama sonucunu eri�im durumu isimli bir de�i�kene atar
bool RobotOperator::checkAccessCode(int _value)
{
	if (_value == decryptCode(getAccessCode()))
	{
		accessState = 1;
		return 1;
	}
	else
		accessState = 0;
	return 0;
}
/// Robota eri�meye �al��an kullan�c�n�n bilgilerini ve eri�im durumunu ekrana yazd�r�r.
void RobotOperator::print()
{
	//RobotControl *robot = new RobotControl;
	cout << "Name Surname: " << getName() << " " << getSurname() << endl;

	system("pause");
}

RobotOperator::~RobotOperator()
{
}
