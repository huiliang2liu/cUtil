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
	string week = "星期天";
	switch (this->week) {
	case 0:week = "星期天";  break;
	case 1:week = "星期一";  break;
	case 2:week = "星期二";  break;
	case 3:week = "星期三";  break;
	case 4:week = "星期四";  break;
	case 5:week = "星期五";  break;
	case 6:week = "星期六";  break;
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
		return "年份错误";
	if (month < 1 || month>12)
		return "月份错误";
	int month_day = TimeUtil::month_day(year,month);
	if (day<1 || day>month_day)
		return "日期错误";
	if ((month == 3 && day >= 21) || (month == 4 && day <= 19))
		return "白羊座";
	if ((month == 4 && day >= 20) || (month == 5 && day <= 20))
		return "金牛座";
	if ((month == 5 && day >= 21) || (month == 6 && day <= 21))
		return "双子座";
	if ((month == 6 && day >= 22) || (month == 7 && day <= 22))
		return "巨蟹座";
	if ((month == 7 && day >= 23) || (month == 8 && day <= 22))
		return "狮子座";
	if ((month == 8 && day >= 23) || (month == 9 && day <= 22))
		return "处女座";
	if ((month == 9 && day >= 23) || (month == 10 && day <= 23))
		return "天秤座";
	if ((month == 10 && day >= 24) || (month == 11 && day <= 22))
		return "天蝎座";
	if ((month == 11 && day >= 23) || (month == 12 && day <= 21))
		return "射手座";
	if ((month == 12 && day >= 22) || (month == 1 && day <= 19))
		return "摩羯座";
	if ((month == 1 && day >= 20) || (month == 2 && day <= 18))
		return "水瓶座";
	return "双鱼座";
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
// 【子时】（23时至01时）夜半，又名子夜、中夜：十二时辰的第一个时辰．鼠
//
// 【丑时】（01时至03时）鸡鸣，又名荒鸡：十二时辰的第二个时辰。牛
//
// 【寅时】（03时至05时）平旦，又称黎明、早晨、时是夜与日的交替之际 虎
//
// 【卯时】（05时至07时）日出，又名破晓、旭日，指太阳刚露脸，初升的时间。 兔
//
// 【辰时】（07时至09时）食时，又名早食，也是吃早饭时间， 龙
//
// 【巳时】（09时至11时）隅中，又名日禺等：临近中午的时候称为隅中。 蛇
//
// 【午时】（11时至13时）日中，又名日正、中午等 马
//
// 【未时】（13时至15时） 日昳，又名日跌、日央等：太阳偏西为日跌。羊
//
// 【申时】（15食至17时） 哺时，又名日铺、夕食等 猴
//
// 【酉时】（17是至19时） 日入，又名日落、傍晚：意为太阳落山的时候。 鸡
//
// 【戌时】（19时至21时） 黄昏，又名日夕、日暮、日晚等：此时太阳已经落山，天将黑未黑。天地昏黄，万物朦胧，故称黄昏。 狗
//
// 【亥时】（21时至23时）人定，又名定昏等：此时夜色已深，人们也已经停止活动，安歇睡眠了。人定也就是人静。 猪
string TimeUtil::time2Zodiac(int time)
{
	if (time > 24 || time < 0)
		return "时间错误";
	if (time >= 23 || time < 1)
		return "子时";
	if (time >= 1 || time < 3)
		return "丑时";
	if (time >= 3 || time < 5)
		return "寅时";
	if (time >= 5 || time < 7)
		return "卯时";
	if (time >= 7 || time < 9)
		return "辰时";
	if (time >= 9 || time < 11)
		return "巳时";
	if (time >= 11 || time < 13)
		return "午时";
	if (time >= 13 || time < 15)
		return "未时";
	if (time >= 15 || time < 17)
		return "申时";
	if (time >= 17 || time < 19)
		return "酉时";
	if (time >= 19 || time < 21)
		return "戌时";
	return "亥时";
}

string TimeUtil::dateExchangeString(string time)
{
	TimeUtil util;
	TimeUtil util1(time.c_str());
	if (util.year < util1.year) 
		return "未来时间";
	else if (util.year == util1.year) {
		if (util.month < util1.month)
			return "未来时间";
		else if (util.month == util1.month) { 
			if (util.day == util1.day)
				return "今天";
			else if (util.day > util1.day) {
				if (util.day == util1.day + 1)
					return "昨天";
				else if (util.day == util1.day + 2)
					return "前天";
				else
					return "更早以前";
			}
			else {
				if (util.day == util1.day - 1)
					return "明天";
				else if (util.day == util1.day - 2)
					return "后天";
				else return "未来时间";
			}
		}
		else
			return "更早以前";
	}
	else 
		return "更早以前";
	
}



