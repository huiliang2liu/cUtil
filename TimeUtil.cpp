#include "stdafx.h"
#include "TimeUtil.h"


TimeUtil::TimeUtil()
{
	time_t timer; time(&timer);
	struct tm t_tm;
	localtime_s(&t_tm,&timer);
	parstime(t_tm);
	mill = timer;
	
}
TimeUtil::TimeUtil(long timestamp)
{ 
	time_t tm = timestamp;
	struct tm t_tm;
	localtime_s(&t_tm, &tm);
	parstime(t_tm);
	mill = timestamp;
}
TimeUtil::TimeUtil(const char* str_time)
{
	struct tm stm;
	int iY, iM, iD, iH, iMin, iS;

	memset(&stm, 0, sizeof(stm));
	iY = atoi(str_time);
	iM = atoi(str_time + 5);
	iD = atoi(str_time + 8);
	iH = atoi(str_time + 11);
	iMin = atoi(str_time + 14);
	iS = atoi(str_time + 17);

	stm.tm_year = iY - 1900;
	stm.tm_mon = iM - 1;
	stm.tm_mday = iD;
	stm.tm_hour = iH;
	stm.tm_min = iMin;
	stm.tm_sec = iS;
	mill = mktime(&stm);
	parstime(stm);
}

string TimeUtil::double2string(double s)
{
	stringstream ss;
	ss << s;
	return ss.str();
}
void TimeUtil::parstime(tm t_tm)
{
	year =  (t_tm.tm_year + 1900);
	month =  (t_tm.tm_mon + 1);
	day =  (t_tm.tm_mday);
	hour =  (t_tm.tm_hour);
	min =  (t_tm.tm_min);
	seconds =  (t_tm.tm_sec);
	ms =  (mill % 1000);
	week = t_tm.tm_wday;
	yday = t_tm.tm_yday;
}
TimeUtil::~TimeUtil()
{
}

long TimeUtil::getTimeMs()
{
	time_t tm = time(NULL);
	return tm;
}

string TimeUtil::getYear()
{
	return  double2string(year);
}

string TimeUtil::getMonth()
{
	return double2string(month);
}

string TimeUtil::getDay()
{
	return double2string(day);
}

string TimeUtil::getHour()
{
	return double2string(hour);
}

string TimeUtil::getMin()
{
	return double2string(min);
}

string TimeUtil::getSeconds()
{
	return double2string(seconds);
}

string TimeUtil::getMs()
{
	return double2string(ms);
}

bool TimeUtil::compare(TimeUtil util)
{
	if(util.mill>this->mill)
		return false;
	return true;
}

bool TimeUtil::leap_year()
{
	return isLeapYear(year);
}


string TimeUtil::weekEn()
{
	string week = "sunday";
	switch (this->week) {
	case 0:week = "sunday"; break;
	case 1:week = "monday"; break;
	case 2:week = "tuesday"; break;
	case 3:week = "wednesday"; break;
	case 4:week = "thursday"; break;
	case 5:week = "friday"; break;
	case 6:week = "saturday"; break;
	}
	return week;
}
string TimeUtil::weekCh()
{
	string week = "������";
	switch (this->week) {
	case 0:week = "������";  break;
	case 1:week = "����һ";  break;
	case 2:week = "���ڶ�";  break;
	case 3:week = "������";  break;
	case 4:week = "������";  break;
	case 5:week = "������";  break;
	case 6:week = "������";  break;
	}
	return week;
}

bool TimeUtil::isLeapYear(int year)
{
	if (year <= 0)
		return false;
	if (year % 100 == 0) {
		if (year % 400 == 0)
			return true;
		else
			return false;
	}
	if (year % 4 == 0)
		return true;
	return false;
}

string TimeUtil::time_to_constellation(int year,int month , int day)
{
	if (year < 1)
		return "��ݴ���";
	if (month < 1 || month>12)
		return "�·ݴ���";
	int month_day = TimeUtil::month_day(year,month);
	if (day<1 || day>month_day)
		return "���ڴ���";
	if ((month == 3 && day >= 21) || (month == 4 && day <= 19))
		return "������";
	if ((month == 4 && day >= 20) || (month == 5 && day <= 20))
		return "��ţ��";
	if ((month == 5 && day >= 21) || (month == 6 && day <= 21))
		return "˫����";
	if ((month == 6 && day >= 22) || (month == 7 && day <= 22))
		return "��з��";
	if ((month == 7 && day >= 23) || (month == 8 && day <= 22))
		return "ʨ����";
	if ((month == 8 && day >= 23) || (month == 9 && day <= 22))
		return "��Ů��";
	if ((month == 9 && day >= 23) || (month == 10 && day <= 23))
		return "�����";
	if ((month == 10 && day >= 24) || (month == 11 && day <= 22))
		return "��Ы��";
	if ((month == 11 && day >= 23) || (month == 12 && day <= 21))
		return "������";
	if ((month == 12 && day >= 22) || (month == 1 && day <= 19))
		return "Ħ����";
	if ((month == 1 && day >= 20) || (month == 2 && day <= 18))
		return "ˮƿ��";
	return "˫����";
}

int TimeUtil::month_day(int year, int month)
{
	if (year < 1)
		return 0;
	if (month < 1 || month>12)
		return 0;
	switch (month) {
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	case 2:
		if (isLeapYear(year))
			return 29;
		else
			return 28;
	}
	return 31;
}
// ����ʱ����23ʱ��01ʱ��ҹ�룬������ҹ����ҹ��ʮ��ʱ���ĵ�һ��ʱ������
//
// ����ʱ����01ʱ��03ʱ�������������ļ���ʮ��ʱ���ĵڶ���ʱ����ţ
//
// ����ʱ����03ʱ��05ʱ��ƽ�����ֳ��������糿��ʱ��ҹ���յĽ���֮�� ��
//
// ��îʱ����05ʱ��07ʱ���ճ����������������գ�ָ̫����¶����������ʱ�䡣 ��
//
// ����ʱ����07ʱ��09ʱ��ʳʱ��������ʳ��Ҳ�ǳ��緹ʱ�䣬 ��
//
// ����ʱ����09ʱ��11ʱ�����У�������خ�ȣ��ٽ������ʱ���Ϊ���С� ��
//
// ����ʱ����11ʱ��13ʱ�����У���������������� ��
//
// ��δʱ����13ʱ��15ʱ�� �Օi�������յ�������ȣ�̫��ƫ��Ϊ�յ�����
//
// ����ʱ����15ʳ��17ʱ�� ��ʱ���������̡�Ϧʳ�� ��
//
// ����ʱ����17����19ʱ�� ���룬�������䡢������Ϊ̫����ɽ��ʱ�� ��
//
// ����ʱ����19ʱ��21ʱ�� �ƻ裬������Ϧ����ĺ������ȣ���ʱ̫���Ѿ���ɽ���콫��δ�ڡ���ػ�ƣ��������ʣ��ʳƻƻ衣 ��
//
// ����ʱ����21ʱ��23ʱ���˶�����������ȣ���ʱҹɫ�������Ҳ�Ѿ�ֹͣ�����Ъ˯���ˡ��˶�Ҳ�����˾��� ��
string TimeUtil::time2Zodiac(int time)
{
	if (time > 24 || time < 0)
		return "ʱ�����";
	if (time >= 23 || time < 1)
		return "��ʱ";
	if (time >= 1 || time < 3)
		return "��ʱ";
	if (time >= 3 || time < 5)
		return "��ʱ";
	if (time >= 5 || time < 7)
		return "îʱ";
	if (time >= 7 || time < 9)
		return "��ʱ";
	if (time >= 9 || time < 11)
		return "��ʱ";
	if (time >= 11 || time < 13)
		return "��ʱ";
	if (time >= 13 || time < 15)
		return "δʱ";
	if (time >= 15 || time < 17)
		return "��ʱ";
	if (time >= 17 || time < 19)
		return "��ʱ";
	if (time >= 19 || time < 21)
		return "��ʱ";
	return "��ʱ";
}

string TimeUtil::dateExchangeString(string time)
{
	TimeUtil util;
	TimeUtil util1(time.c_str());
	if (util.year < util1.year) 
		return "δ��ʱ��";
	else if (util.year == util1.year) {
		if (util.month < util1.month)
			return "δ��ʱ��";
		else if (util.month == util1.month) { 
			if (util.day == util1.day)
				return "����";
			else if (util.day > util1.day) {
				if (util.day == util1.day + 1)
					return "����";
				else if (util.day == util1.day + 2)
					return "ǰ��";
				else
					return "������ǰ";
			}
			else {
				if (util.day == util1.day - 1)
					return "����";
				else if (util.day == util1.day - 2)
					return "����";
				else return "δ��ʱ��";
			}
		}
		else
			return "������ǰ";
	}
	else 
		return "������ǰ";
	
}



