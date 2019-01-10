#include "Encryption.h"
#include "RobotControl.h"


/// Robot oluþturulurken girilen 4 basamaklý sayýyý þifrelemede kullanýlýr.
/// int deðer döndürür

int RobotOperator::encryptCode(int _value)
{
	Encryption tool;
	return tool.encrypt(_value);
}
/// Robota eriþim saðlanmaya çalýþýldýðýnda þifrelenmiþ eriþim kodunu çözüp kullanýcýnýn girdiði sayýyla kýyaslanabilir hale getirmek için kullanýlýr
///int deðer döndürür
int RobotOperator::decryptCode(int _value)
{
	Encryption tool;
	return tool.decrypt(_value);
}
/// Constructor fonksiyon, oluþturulurken robota eriþim için 4 basamaklý int bir sayý alýr
RobotOperator::RobotOperator(int _accessCode)
{
	setAccessCode(_accessCode);
}
/// Private tanýmlanan eriþim kodunu çaðýrmada kullanýlýr
int RobotOperator::getAccessCode()
{
	return accessCode;
}
/// Robot oluþturulurken girilen 4 basamaklý int sayýyý þifrelemeye yarar
void RobotOperator::setAccessCode(int _accessCode)
{
	accessCode = encryptCode(_accessCode);
}
/// Robota eriþim için kullanýcý bilgilerinin alýnmasýnda kullanýlýr
void RobotOperator::setName(string _name)
{
	name = _name;
}
string RobotOperator::getName()
{
	return name;
}
/// Robota eriþim için kullanýcý bilgilerinin alýnmasýnda kullanýlýr
void RobotOperator::setSurname(string _surname)
{
	surname = _surname;
}
string RobotOperator::getSurname()
{
	return surname;
}
/// Robota eriþim için girilen 4 basamaklý sayýyý eriþim koduyla kýyaslar
/// Kýyaslama sonucunu eriþim durumu isimli bir deðiþkene atar
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
/// Robota eriþmeye çalýþan kullanýcýnýn bilgilerini ve eriþim durumunu ekrana yazdýrýr.
void RobotOperator::print()
{
	//RobotControl *robot = new RobotControl;
	cout << "Name Surname: " << getName() << " " << getSurname() << endl;

	system("pause");
}

RobotOperator::~RobotOperator()
{
}
