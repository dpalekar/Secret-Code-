#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>
#include "Reports.h"
//#include "BookInfo.h"

using namespace std;

// Default Constructor
Reports::Reports() {}

// Destructor
Reports::~Reports() {}

const int ARR_SIZE = 30;

void Reports::module(BookInfo book[], int SIZE)
{
	int choice = 0;

	//Menu-driven program for user to select report type
	while (choice != 7)
	{
		cout << "\t\t Serendipity BookSellers \t\t\n";
		cout << " \t\t\t Reports \t\t \n";
		cout << " 1. Inventory listing \n";
		cout << " 2. Inventory Wholesale Value \n";
		cout << " 3. Inventory Retail Value \n";
		cout << " 4. Listed by Quantity \n";
		cout << " 5. Listed by Cost \n";
		cout << " 6. Listed by Age \n";
		cout << " 7. Return to Main Menu \n";
		cout << endl;

		cout << "Enter your choice: ";
		cin >> choice;

		//Validate input
		while (choice < 1 || choice > 7)
		{
			cout << "Please enter a valid choice in the range 1 - 7. \n";
			cout << "Enter your choice: ";
			cin >> choice;
		}

		switch (choice)
		{
		case 1:
			reportInventoryList(book, SIZE);
			break;
		case 2:
			reportWholesaleValue(book, SIZE);
			break;

		case 3:
			reportRetailValue(book, SIZE);
			break;

		case 4:
			reportListByQuantity(book, SIZE);
			break;
		case 5:
			reportListByCost(book, SIZE);
			break;
		case 6:
			reportListByAge(book, SIZE);
			break;
		case 7:
			;
		}
	}
}
// Report Inventory List
void Reports::reportInventoryList(BookInfo book[], int SIZE)
{
	cout << "You selected report inventory list. ";
	cout << endl;
	cout << " \n\t\t\t\t\t Serendipity Booksellers \n";
	cout << " \t\t\t\t\t Inventory List Report\n\n";
	cout << "ISBN\t\tBook Title\t\t\t\t\t\t    Author\t\t    Publisher\t\t\t      DateAdded\t";
	cout << " WholesalePrice\t     Quantity\t     RetailPrice \n";

	for (int index = 0; index < SIZE; index++)
	{
		if (book[index].getisbn() != "")
		{
			cout << setw(15) << left << book[index].getisbn();
			cout << setw(60) << left << book[index].getTitle();
			cout << setw(25) << left << book[index].getAuthor();
			cout << setw(25) << left << book[index].getPublisher();
			Date date1(book[index].getDay(), book[index].getMonth(), book[index].getYear());
			cout << setw(10) << right;
			cout << date1;
			cout << setw(15) << right << fixed << showpoint << setprecision(2);
			cout << book[index].getWholesalePrice();
			cout << setw(15) << right << fixed << showpoint << setprecision(2);
			cout << book[index].getQtyOnHand();
			cout << setw(20) << right << fixed << showpoint << setprecision(2);
			cout << book[index].getRetailPrice() << endl;
		}
	}
	cout << endl;
}

//Report Wholesale Value
void Reports::reportWholesaleValue(BookInfo book[], int SIZE)
{
	cout << "\n You selected report Wholesale Value \n\n ";
	double itemTotal[ARR_SIZE];
	double total = 0;

	for (int index = 0; index < SIZE; index++)
	{
		itemTotal[index] = 0;

		if (book[index].getisbn() != "")
		{
			itemTotal[index] = (book[index].getQtyOnHand() * book[index].getWholesalePrice());
			total += itemTotal[index];
		}
	}

	cout << "\n Book Title \t\t\t\t\t\t    Quantity\t  WholesalePrice \tItemTotal\n\n";
	for (int index = 0; index < SIZE; index++)
	{
		if (book[index].getisbn() != "")
		{
			cout << setw(55) << left << book[index].getTitle() << right << setw(10) << book[index].getQtyOnHand();
			cout << right << setw(20) << fixed << showpoint << setprecision(2);
			cout << book[index].getWholesalePrice();
			cout << setw(20) << right << fixed << showpoint << setprecision(2);
			cout << itemTotal[index] << endl;
		}
	}
	cout << "\n The total Wholesale Value of Inventory is : $" << total << endl;						//Calculate the total Wholesale Value of the inventory
	cout << endl;
}

//Report Retail Value
void Reports::reportRetailValue(BookInfo book[], int SIZE)
{
	cout << "\n You selected report retail value.\n";
	double itemTotal[ARR_SIZE];
	double total = 0;

	for (int index = 0; index < SIZE; index++)
	{
		itemTotal[index] = 0;

		if (book[index].getisbn() != "")
		{
			itemTotal[index] = (book[index].getQtyOnHand() * book[index].getRetailPrice());					//Calculate itemTotal for each title
			total += itemTotal[index];
		}
	}

	cout << "Book Title \t\t\t\t\t      Quantity\t\tRetailPrice\t   ItemTotal\n\n";
	for (int index = 0; index < SIZE; index++)
	{
		if (book[index].getisbn() != "")
		{
			cout << setw(55) << left << book[index].getTitle() << right << setw(6) << book[index].getQtyOnHand();
			cout << right << setw(20) << fixed << showpoint << setprecision(2);
			cout << book[index].getRetailPrice();
			cout << right << setw(20) << fixed << showpoint << setprecision(2);
			cout << itemTotal[index] << endl;
		}
	}
	cout << "\n The total Retail Value of Inventory is $: " << total << endl;								//Calculate the total Retail Value of the inventory
	cout << endl;
}

//Report List by Quantity
void Reports::reportListByQuantity(BookInfo book[], int SIZE)
{
	cout << "\n You selected report list by quantity.\n\n ";

	string bookarrTitle[ARR_SIZE];
	int bookarrQty[ARR_SIZE];

	for (int index = 0; index < SIZE; index++)
	{
		bookarrTitle[index] = book[index].getTitle();
		bookarrQty[index] = book[index].getQtyOnHand();
	}
	selectionSort2descending(bookarrQty, bookarrTitle, SIZE);						//Sort the titles based on Quantity on Hand
	cout << "Book Title\t\t\t\t\t" << "\t\tQuantityOnHand\n";
	for (int index = 0; index < SIZE; index++)
	{
		cout << endl;
		if (book[index].getisbn() != "")
		{
			cout << setw(55) << left << bookarrTitle[index];
			cout << setw(20) << right << bookarrQty[index] << endl;
		}
	}
	cout << endl;
}

//Report List by Wholesale Cost
void Reports::reportListByCost(BookInfo book[], int SIZE)
{
	cout << " You selected report list by cost.\n\n";
	string bookarrTitle[ARR_SIZE];
	double bookarrWPrice[ARR_SIZE];

	for (int index = 0; index < SIZE; index++)
	{
		bookarrTitle[index] = book[index].getTitle();
		bookarrWPrice[index] = book[index].getWholesalePrice();
	}
	selectionSort2descending(bookarrWPrice, bookarrTitle, SIZE);					//Use Selection Sort Algorithm to sort the data in descending order based on wholesale price 
	cout << "Book Title\t\t\t\t\t" << "\t\tWholesalePrice\n";

	for (int index = 0; index < SIZE; index++)
	{
		if (book[index].getisbn() != "")
		{
			cout << endl;
			cout << setw(55) << left << bookarrTitle[index];
			cout << setw(20) << right << fixed << showpoint << setprecision(2) <<  bookarrWPrice[index] << endl;
		}
	}
	cout << endl;
}

//Report List by Age
void Reports::reportListByAge(BookInfo book[], int SIZE)
{
	cout << "\n You selected report list by age.\n";
	int bookarrAge[ARR_SIZE];
	string bookarrTitle[ARR_SIZE];

	int monththen, monthnow, yearthen, yearnow;
	int age, agemonths, ageyears;

	cout << "\n Enter the current year: ";
	cin >> yearnow;
	cout << "\n Enter the current month: ";
	cin >> monthnow;

	for (int index = 0; index < SIZE; index++)											//Calculate  the age based on the date added
	{

		if (book[index].getTitle() != "") {
			bookarrTitle[index] = book[index].getTitle();

			monththen = book[index].getMonth();
			yearthen = book[index].getYear();

			if (monththen < monthnow && yearthen < yearnow)
			{
				ageyears = yearnow - yearthen;
				agemonths = monthnow - monththen;
				bookarrAge[index] = (12 * ageyears) + agemonths;
			}
			else if (monththen < monthnow && yearthen == yearnow)
			{
				agemonths = monthnow - monththen;
				bookarrAge[index] = agemonths;
			}
			else
			{
				ageyears = (yearnow - yearthen) - 1;
				agemonths = 12 - (monththen - monthnow);
				bookarrAge[index] = (12 * ageyears) + agemonths;
			}
		}
	}
	
	selectionSort2descending(bookarrAge, bookarrTitle, SIZE);							//Sort the arrays based on Months on Shelf
	cout << "\nBook Title\t\t\t\t" << "\t\t\t Months on Shelf\n";
	for (int index = 0; index < SIZE; index++)
	{
		
		if (book[index].getWholesalePrice() != 0.0)
		{
			cout << endl;
			cout << setw(55) << left << bookarrTitle[index];
			cout << setw(20) << right << bookarrAge[index] << endl;
		}
	}
	cout << endl;
}

//Selection Sort function (overloaded function)
void Reports::selectionSort2descending(int array1[], string array2[], int size)
{
	int startScan, minIndex, maxValue1;
	string maxValue2;
	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		maxValue1 = array1[startScan];
		maxValue2 = array2[startScan];
		for (int index = startScan + 1; index < size; index++)
		{
			if (array1[index] > maxValue1)
			{
				maxValue1 = array1[index];
				minIndex = index;
				maxValue2 = array2[index];
			}
		}
		array1[minIndex] = array1[startScan];
		array1[startScan] = maxValue1;

		array2[minIndex] = array2[startScan];
		array2[startScan] = maxValue2;
	}
}
void Reports::selectionSort2descending(double array1[], string array2[], int size)
{
	int startScan, minIndex;
	double maxValue1;
	string maxValue2;
	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		maxValue1 = array1[startScan];
		maxValue2 = array2[startScan];
		for (int index = startScan + 1; index < size; index++)
		{
			if (array1[index] > maxValue1)
			{
				maxValue1 = array1[index];
				minIndex = index;
				maxValue2 = array2[index];
			}
		}
		array1[minIndex] = array1[startScan];
		array1[startScan] = maxValue1;

		array2[minIndex] = array2[startScan];
		array2[startScan] = maxValue2;
	}
}