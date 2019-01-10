#include "Encryption.h"
#include <iostream>

using namespace std;
Encryption::Encryption()
{

}

int Encryption::encrypt(int _value)
{
	int value = _value;
	int temp;
	for (int i = 0; i < 4 ;i++)
	{
		encdigit[i] = value % 10;
		value = value / 10;
	}
	for (int i = 0; i < 4; i++)
	{
		encdigit[i] = encdigit[i] + 7;
		encdigit[i] = encdigit[i] % 10;
		
	}
	for (int i = 0; i < 2; i++)
	{
		temp = encdigit[i];
		encdigit[i] = encdigit[i + 2];
		encdigit[i + 2] = temp;
	}

	return (encdigit[0] * 1 + encdigit[1] * 10 + encdigit[2] * 100 + encdigit[3] * 1000);
}

int Encryption::decrypt(int _value)
{
	int value = _value;
	int temp;
	for (int i = 0; i < 4; i++)
	{
		decdigit[i] = value % 10;
		value = value / 10;
	}
	for (int i = 0; i < 2; i++)
	{
		temp = decdigit[i];
		decdigit[i] = decdigit[i + 2];
		decdigit[i + 2] = temp;
	}
	for (int i = 0; i < 4; i++)
	{
		if(decdigit[i]<7)
		{
			decdigit[i] = decdigit[i] + 3;
		}
		else if(decdigit[i]>7)
		{
			decdigit[i] = decdigit[i] - 7;
		}		
	}
	return (decdigit[0] * 1 + decdigit[1] * 10 + decdigit[2] * 100 + decdigit[3] * 1000);
}

Encryption::~Encryption()
{
}
