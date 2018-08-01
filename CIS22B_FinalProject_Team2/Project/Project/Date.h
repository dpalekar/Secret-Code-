#ifndef DATE_H
#define DATE_H
#include <iostream>
class Date
{
private:
	int day;
	int month;
	int year;

public:
	//Default Constructor
	Date();

	//Constructor
	Date(int d, int m, int y);

	~Date();

	friend std::ostream& operator<<(std::ostream& os, const Date& date);

	//Setters
	void setDay(int dy);
	void setMonth(int mt);
	void setYear(int yr);
	//Accessors
	int getDay() const;
	int getMonth() const;
	int getYear() const;



};

#endif
