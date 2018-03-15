#include "stdafx.h"
#include "StringUtil.h"


StringUtil::StringUtil()
{
}


StringUtil::~StringUtil()
{
}
string StringUtil::double2string(double s)
{
	ss << s;
	return ss.str();
}
int StringUtil::string2int(string s)
{  
	stringstream ss(s);
	int num;
	ss >> num;
	return num;
}

long StringUtil::string2long(string s)
{
	stringstream ss(s);
	long num;
	ss >> num;
	return num;
}
double StringUtil::string2double(string s)
{
	stringstream ss(s);
	double num;
	ss >> num;
	return num;
}
float StringUtil::string2float(string s)
{
	stringstream ss(s);
	float num;
	ss >> num;
	return num;
}



