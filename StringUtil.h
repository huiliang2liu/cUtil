#pragma once
#include<string>
#include<sstream>
using namespace std;
class StringUtil
{

public:
	StringUtil();
	~StringUtil();
	
	/*将整数转化为string*/
	 string double2string(double );
	/*将string转化为int*/
	  int string2int(string);
	  long string2long(string);
	  double string2double(string);
	  float string2float(string);
private :
	stringstream ss;
};

