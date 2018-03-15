#include "stdafx.h"
#include "test.h"


test::test()
{
	
}


test::~test()
{
}
void test::addList(string value) {
	mList.push_back(value);
}
void test::addMap(string key, string value) {
	mMap.insert(pair<string, string>(key, value));
}
void test::printList() {
	cout << endl;
	cout << sizeof(mList) << endl;
	list<string> ::iterator iterator;
	for (iterator =mList.begin(); iterator!=mList.end(); iterator++)
	{
		cout << *iterator << "\t";
	}
}
void test::printMap() {
	cout << endl;
	cout << mMap.size() << endl;
	map<string, string>::iterator iterator;
	for (iterator = mMap.begin(); iterator!=mMap.end(); iterator++)
	{
		cout <<"key="<<iterator->first << "\t" <<"value="<<iterator->second << "\t";
	}
}
