#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "BookData.h"
#include "BookInfo.h"
#include "Date.h"
#include "Cashier.h"
#include"InventoryMenu.h"
#include "searchfor.h"
#include "Module.h"
#include "Reports.h"
#include <sstream>

using namespace std;



int main()
{
	
	const int SIZE = 30;

	
	fstream infile;
	infile.open("booklist.txt");
	if (infile.is_open())
	{
		cout << "Inventory accessed successfully.\n\n";
	}
	else
	{
		cout << "File NOT opened. \n";
	}
	
	//Declare an array of book objects of the BookInfo class
	BookInfo book[SIZE];

	string bkISBN, bkTitle, bkAuthor, bkPublisher;
	int qty, bkDay, bkMon, bkYear;
	double wPrice, rPrice;

	string  input;

	//Parse input data reading in one line/record at a time
	int j = 0;
	while (getline(infile, input))
	{
		istringstream ss(input);
		string token;
		string arr[10];
		for (int i = 0; i < 10; i++)
		{
			getline(ss, token, ',');
			arr[i] = token;
			
		}
		

		bkISBN = arr[0];
	
		wPrice = stod(arr[1]);
	
		qty = stoi(arr[2]);

		rPrice = stod(arr[3]);
	
		bkDay = stoi(arr[4]);

		bkMon = stoi(arr[5]);

		bkYear = stoi(arr[6]);

		bkTitle = arr[7];

		bkAuthor = arr[8];

		bkPublisher = arr[9];

		//Populate the book objects of the BookInfo data type using the overloaded constructor
		book[j] = BookInfo(bkISBN, wPrice, qty, rPrice, bkDay, bkMon, bkYear, bkTitle, bkAuthor, bkPublisher);
		j++;
	}

	
	// Create module objects
	// Demonstrates Polymorphism

	Cashier cashierModule;
	Module* cashierpointer = &cashierModule;

	Inventory inventoryModule;
	Module* inventorypointer = &inventoryModule;

	Reports reportsModule;
	Module* reportspointer = &reportsModule;

	int choice = 0;

	while (choice != 4)
	{
		cout << "\t\t  Serendipity Booksellers \t\t\n";
		cout << "\t\t\t Main Menu \t\t\t \n";
		cout << "1. Cashier Module \n";
		cout << "2. Inventory Database Module \n";
		cout << "3. Report Module \n";
		cout << "4. Exit \n";
		cout << endl;

		cout << "Enter your choice: ";
		cin >> choice;

		//Validate input
		while (choice < 1 || choice > 4)
		{
			cout << "\n Please enter a number in the range 1 - 4: ";
			cout << "\n Enter your choice: ";
			cin >> choice;
		}

		switch (choice)
		{
		case 1:
			cashierpointer->module(book, SIZE);
			break;
		case 2:
			inventorypointer->module(book, SIZE);
			break;

		case 3:
			reportspointer->module(book, SIZE);
			break;

		case 4:;
		}

	}

	// close file
	infile.close();

	// open temporary file
	// use overloaded << opertor to write objects into file
	ofstream outfile;
	outfile.open("temp.txt");

	for (int i = 0; i < SIZE; i++) {

		if (book[i].getisbn() != "") {

			outfile << book[i];
		}

	}

	// close file
	outfile.close();
	// delete original file
	remove("booklist.txt");
	// rename temporary file
	rename("temp.txt", "booklist.txt");


	system("pause");
	return 0;
}
