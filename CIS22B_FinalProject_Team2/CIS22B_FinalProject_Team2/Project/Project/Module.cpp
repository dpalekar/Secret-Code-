#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdio.h>
#include "Module.h"
#include "BookInfo.h"
#include "BookData.h"
//#include "Date.h"
#include "searchfor.h"
using namespace std;

// default constructor
Module::Module() {}

// destructor
Module::~Module() {}

void Module::module(BookInfo book[], const int SIZE) {

	cout << "You have selected Module.\n" << endl;

	cout << "\t\t\t\t\t\tSerendipity Booksellers Entire Inventory\n " << endl;
	cout << "__________________________________________________________________________________________" << endl;
	for (int index = 0; index < SIZE; index++)
	{

		if (book[index].getWholesalePrice() != 0.0)
		{
			cout << endl;
			cout << "Book " << index + 1 << endl;
			printInfo(book, index);
		}
	}
	cout << endl;

	
}
