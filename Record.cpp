#include "Record.h"

Record::Record()
{
}

bool Record::openFile()
{
	file.open(filename, ios::out | ios::in);
	if (file.fail()) {
		openFile();
		return false;
	}
	else {
		return true;
	}
}

bool Record::closeFile()
{
	file.close();
	if (file.is_open())
	{
		return false;
	}
	return true;
}

void Record::setFileName(string name)
{

	filename = name;

}

string Record::readLine()
{
	string line;
	Record::file.open(filename);
	for (int i = 0; i < count; i++)
	{
		getline(file, line);

	}
	Record::closeFile();
	return line;
}

bool Record::writeLine(string str)
{

	file << str << endl;
	file.close();
	count++;
	return true;
}

void Record::setPose(Pose _pose)
{
	pose = _pose;
}

Pose Record::getPose()
{
	return pose;
}

Record::~Record()
{
}


