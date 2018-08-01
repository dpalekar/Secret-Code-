#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include "BookInfo.h"
#include "searchfor.h"
using namespace std;

int searchForISBN(string searchISBN, BookInfo book[], const int ARR_SIZE)
{

	bool found = false;
	int index = 0;

	while (!found && index < ARR_SIZE)
	{
		if (book[index].getisbn() == searchISBN)
			found = true;
		else
			index++;
	}

	if (found)
		return index;
	else
		return -1;
}

int getIndex(BookInfo book[], const int ARR_SIZE) {

	bool found = false;
	int index = 0;

	while (!found && index < ARR_SIZE)
	{
		if (book[index].getisbn() == "")
			found = true;
		else
			index++;
	}
	return index;
}

void printInfo(BookInfo book[], int index) {

	cout << "\nISBN: " << book[index].getisbn() << endl;
	cout << "Title: " << book[index].getTitle() << endl;
	cout << "Author: " << book[index].getAuthor() << endl;
	cout << "Publisher: " << book[index].getPublisher() << endl;
	cout << "Wholesale Price: " << book[index].getWholesalePrice() << endl;
	cout << "Quantity on Hand: " << book[index].getQtyOnHand() << endl;
	cout << "Retail Price: " << book[index].getRetailPrice() << endl;
	cout << "Month added: " << book[index].getMonth() << endl;
	cout << "Day added: " << book[index].getDay() << endl;
	cout << "Year added: " << book[index].getYear() << endl;
	
}