#pragma once
class Encryption
{
public:
	Encryption();
	int encrypt(int _value);
	int decrypt(int _value);
	int encdigit[4];
	int decdigit[4];

	~Encryption();
};

