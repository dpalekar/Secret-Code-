#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>
#include "InventoryMenu.h"
#include "searchfor.h"
#include "BookInfo.h"
#include "BookData.h"
#include "Date.h"

using namespace std;

// Default constructor
Inventory::Inventory() {}

// Destructor
Inventory::~Inventory() {}

void Inventory::module(BookInfo book[], int SIZE)
{	
	// Display menu
	int choice = 0;

	while (choice != 5)
	{
		cout << "\t\t Serendipity BookSellers \t\t\n";
		cout << "\t\t   Inventory Database \t\t\n";
		cout << " 1. Look up a Book \n";
		cout << " 2. Add a Book \n";
		cout << " 3. Edit a Book \n";
		cout << " 4. Delete a Book \n";
		cout << " 5. Return to the Main Menu\n";
		cout << endl;

		cout << " Enter your Choice : ";
		cin >> choice;

		//Validate input
		while (choice < 1 || choice > 5)
		{
			cout << "Please enter a valid choice in the range of 1 - 5. \n ";
			cout << " Enter your Choice : ";
			cin >> choice;
		}

		switch (choice)
		{
		case 1:
			lookUpBook(book, SIZE);
			break;
		case 2:
			addBook(book, SIZE);
			break;

		case 3:
			editBook(book, SIZE);
			break;

		case 4:
			deleteBook(book, SIZE);
			break;
		case 5:
			cout << "You selected item 5. \n";
			break;
		}

	}

}

void Inventory::lookUpBook(BookInfo book[], int SIZE)
{

	cout << "You selected look up book. \n";

	string searchedISBN;
	int searchedIndex;

	cout << "Enter the ISBN of the book you would like to look up: ";
	cin >> searchedISBN;

	searchedIndex = searchForISBN(searchedISBN, book, SIZE);

	// Search for isbn
	// if found print book info
	// if not found display message
	if (searchedIndex == -1) {

		cout << "This book was not found in the inventory." << endl;
	}
	else {

		printInfo(book, searchedIndex);
	}

}

void Inventory::addBook(BookInfo book[], int SIZE)
{

	string bkISBN, bkTitle, bkAuthor, bkPublisher;
	int qty, bkDay, bkMon, bkYear;
	double wPrice, rPrice;


	string searchedISBN;
	int searchedIndex;
	int addedCopies;

	// get isbn
	cout << "You selected add book.";
	cout << "\nEnter the ISBN of the book you would like to add: ";
	cin >> searchedISBN;

	// search for isbn
	searchedIndex = searchForISBN(searchedISBN, book, SIZE);

	// if found, update date and copoes
	if (searchedIndex != -1) {

		cout << "The ISBN you searched was found in the inventory." << endl;
		cout << "Enter the number of copies you would like to add: ";
		cin >> addedCopies;
		book[searchedIndex].setQtyOnHand(book[searchedIndex].getQtyOnHand() + addedCopies);

		cout << "\nEnter the day for date added: ";
		cin >> bkDay;

		cout << "\nEnter the month for date added: ";
		cin >> bkMon;

		cout << "\nEnter the year for date added: ";
		cin >> bkYear;

		// set values
		book[searchedIndex].setMonth(bkMon);
		book[searchedIndex].setDay(bkDay);
		book[searchedIndex].setYear(bkYear);
		Date date(bkDay, bkMon, bkYear);
		cout << addedCopies << " copies of book with ISBN " << searchedISBN << " were added to the inventory on " << date << endl;

	}
	// if not found, create new record
	else {

		searchedIndex = getIndex(book, SIZE);
		cout << "The ISBN you searched was not found in the inventory." << endl;
		cout << "A new record will be created for this ISBN" << endl;
		if (searchedIndex < SIZE) {
			cout << "\nEnter wholesale price: ";
			cin >> wPrice;

			cout << "\nEnter quantity to be added: ";
			cin >> qty;

			cout << "\nEnter retail price: ";
			cin >> rPrice;

			cout << "\nEnter the day for date added: ";
			cin >> bkDay;

			cout << "\nEnter the month for date added: ";
			cin >> bkMon;

			cout << "\nEnter the year for date added: ";
			cin >> bkYear;

			cout << "\nEnter the book title: ";
			cin.ignore();
			getline(cin, bkTitle);


			cout << "\nEnter the book author: ";

			getline(cin, bkAuthor);

			cout << "\nEnter the publisher: ";
			getline(cin, bkPublisher);
			

			book[searchedIndex] = BookInfo(searchedISBN, wPrice, qty, rPrice, bkDay, bkMon, bkYear, bkTitle, bkAuthor, bkPublisher);

			cout << "\n New book record created. \n";
			cout << "The information for the book created is: \n";
			printInfo(book, searchedIndex);
		}

		else {

			cout << "A book cannot be added to the inventory at this time." << endl;
		}
	}

}

void Inventory::editBook(BookInfo book[], int SIZE)
{

	string bkISBN, bkTitle, bkAuthor, bkPublisher;
	int qty, bkDay, bkMon, bkYear;
	double wPrice, rPrice;


	string searchedISBN;
	int searchedIndex;


	cout << "You selected edit book.";
	cout << "\nEnter the ISBN of the book you would like to edit: ";
	cin >> searchedISBN;

	// search for isbn
	searchedIndex = searchForISBN(searchedISBN, book, SIZE);

	// if not found, display message
	if (searchedIndex == -1) {

		cout << "This book was not found in the inventory." << endl;
	}
	// if found, ask user for updated values for book attributes
	else {

		cout << "\nEnter wholesale price: ";
		cin >> wPrice;

		cout << "\nEnter quantity to be added: ";
		cin >> qty;

		cout << "\nEnter retail price: ";
		cin >> rPrice;

		cout << "\nEnter the day for date added: ";
		cin >> bkDay;

		cout << "\nEnter the month for date added: ";
		cin >> bkMon;

		cout << "\nEnter the year for date added: ";
		cin >> bkYear;

		cout << "\nEnter the book title: ";
		cin.ignore();
		getline(cin, bkTitle);

		cout << "\nEnter the book author: ";

		getline(cin, bkAuthor);

		cout << "\nEnter the publisher: ";
		getline(cin, bkPublisher);



		book[searchedIndex] = BookInfo(searchedISBN, wPrice, qty, rPrice, bkDay, bkMon, bkYear, bkTitle, bkAuthor, bkPublisher);

		cout << "\n Book has been edited. \n";
		cout << "The information for the book created is: \n";
		printInfo(book, searchedIndex);

	}

}

void Inventory::deleteBook(BookInfo book[], int SIZE)
{

	cout << "You selected delete up book. \n";

	string searchedISBN;
	int searchedIndex;
	char confirm;

	cout << "Enter the ISBN of the book you would like to delete: ";
	cin >> searchedISBN;

	// search for isbn
	searchedIndex = searchForISBN(searchedISBN, book, SIZE);

	// if not found, display message
	if (searchedIndex == -1) {

		cout << "This book was not found in the inventory." << endl;
	}

	// if found, validate delete choice, and then delete if confirmed
	else {
		cout << "The information for the book selected is: \n";
		printInfo(book, searchedIndex);

		cout << "Are you sure you want to delete this item? ";
		cin >> confirm;

		if (confirm == 'Y' || confirm == 'y')
		{
			book[searchedIndex] = BookInfo();
			cout << "The item you selected has been deleted.\n";
		}
		else
			cout << "No items deleted from inventory. \n";
	}

}