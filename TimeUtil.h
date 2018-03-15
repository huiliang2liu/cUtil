#pragma once
#include<time.h>
#include<string>
#include<sstream>
#include<iostream>
using namespace std;
class TimeUtil
{
	
public:
	/*��ȡϵͳʱ��*/
	TimeUtil();
	~TimeUtil();
	/*��ʱ���ת��Ϊʱ��*/
	TimeUtil(long);
	/*�ַ���ʱ��ת��Ϊʱ��*/
	TimeUtil(const char*);
	/*��ȡʱ���*/
	 long getTimeMs();
	 /*��ȡ���*/
	 string getYear();
	 /*��ȡ�·�*/
	 string getMonth();
	 /*��ȡ��*/
	 string getDay();
	 /*��ȡСʱ*/
	 string getHour();
	 /*��ȡ����*/
	 string getMin();
	 /*��ȡ��*/
	 string getSeconds();
	 /*��ȡ��ǰʱ��ĺ���*/
	 string getMs();
	 /*�Ƚ�����ʱ��Ĵ�С*/
	 bool compare(TimeUtil);
	 /*��ǰʱ���ǲ�������*/
	 bool leap_year();
	 /*��ȡӢ����*/
	 string weekEn();
	 /*��ȡ������*/
	 string weekCh();
	 /*�жϵ�ǰʱ���Ƿ�Ϊ����*/
	 static bool isLeapYear(int);
	 /*��ʱ��ת��Ϊ��������һ������Ϊ��ݣ��ڶ�������Ϊ�·ݣ�����������Ϊ��*/
	 static string time_to_constellation(int,int,int);
	 /*��ȡĳ��ĳ�µ���������һ������Ϊ��ݣ��ڶ�������Ϊ�·�*/
	 static int month_day(int, int);
	 /*��ʱ��ת��Ϊ��Ф*/
	 static string time2Zodiac(int);
	 /*��ʱ��ת��Ϊ���� ���� ǰ�� ������ǰ*/
	 static string dateExchangeString(string);
	 
private :
	int year;
	int month;
	int day;
	int hour;
	int min;
	int seconds;
	int ms;
	int week;
	int yday;
	long mill;
	string double2string(double);
	void parstime(struct tm);
	
};

