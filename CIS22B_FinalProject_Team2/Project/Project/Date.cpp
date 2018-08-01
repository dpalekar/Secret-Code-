#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Date.h"
//Default Constructor
Date::Date()
{
	day = '\0';
	month = '\0';
	year = '\0';
}


//Constructor
Date::Date(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}

Date::~Date() {}

std::ostream& operator<<(std::ostream& os, const Date& date) {

	os << date.month << "/" << date.day << "/" << date.year;


	return os;
}

//Setters
void Date::setDay(int dy) {

	day = dy;
}

void Date::setMonth(int mt) {

	month = mt;
}
void Date::setYear(int yr) {

	year = yr;
}

//Accessors
int Date::getDay() const
{
	return day;
}

int Date::getMonth() const
{
	return month;
}

int Date::getYear() const
{
	return year;
}