#pragma once
#include<iostream>
using namespace std;
class Date
{
private:
	int month;
	int year;
	int date;
public:
	Date()
	{
		month = 0;
		year = 0;
		date = 0;
	}
	Date(int m, int y, int d)
	{
		month = m;
		year = y;
		date = d;
	}
	int GetDate()
	{
		return date;
	}
	int GetMonth()
	{
		return month;
	}
	int GetYear()
	{
		return year;
	}
	void SetDate(int d)
	{
		date = d;
	}
	void SetMonth(int d)
	{
		month = d;
	}
	void SetYear(int d)
	{
		year = d;
	}
};
