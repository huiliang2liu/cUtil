#pragma once
#include<time.h>
#include<string>
#include<sstream>
#include<iostream>
using namespace std;
class TimeUtil
{
	
public:
	/*获取系统时间*/
	TimeUtil();
	~TimeUtil();
	/*将时间戳转化为时间*/
	TimeUtil(long);
	/*字符串时间转化为时间*/
	TimeUtil(const char*);
	/*获取时间戳*/
	 long getTimeMs();
	 /*获取年份*/
	 string getYear();
	 /*获取月份*/
	 string getMonth();
	 /*获取天*/
	 string getDay();
	 /*获取小时*/
	 string getHour();
	 /*获取分钟*/
	 string getMin();
	 /*获取秒*/
	 string getSeconds();
	 /*获取当前时间的毫秒*/
	 string getMs();
	 /*比较两个时间的大小*/
	 bool compare(TimeUtil);
	 /*当前时间是不是闰年*/
	 bool leap_year();
	 /*获取英文周*/
	 string weekEn();
	 /*获取中文周*/
	 string weekCh();
	 /*判断当前时间是否为闰年*/
	 static bool isLeapYear(int);
	 /*将时间转化为星座，第一个参数为年份，第二个参数为月份，第三个参数为天*/
	 static string time_to_constellation(int,int,int);
	 /*获取某年某月的天数，第一个参数为年份，第二个参数为月份*/
	 static int month_day(int, int);
	 /*将时间转化为生肖*/
	 static string time2Zodiac(int);
	 /*将时间转化为今天 昨天 前天 更早以前*/
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

