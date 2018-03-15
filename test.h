#pragma once
#include<contrib\minizip\zip.h>
#include<iostream>
#include<string>
#include<map>
#include<list>
using namespace std;
class test
{
public:
	test();
	~test();
	void addList(string);
	void addMap(string,string);
	void printList();
	void printMap();

private:
	list<string> mList;
	map<string, string> mMap;
};

