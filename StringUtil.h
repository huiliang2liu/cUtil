#pragma once
#include<string>
#include<sstream>
using namespace std;
class StringUtil
{

public:
	StringUtil();
	~StringUtil();
	
	/*������ת��Ϊstring*/
	 string double2string(double );
	/*��stringת��Ϊint*/
	  int string2int(string);
	  long string2long(string);
	  double string2double(string);
	  float string2float(string);
private :
	stringstream ss;
};

