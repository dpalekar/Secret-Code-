#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include "Cashier.h"
#include "BookInfo.h"
#include "BookData.h"
#include "searchfor.h"
#include "templatefxns.h"
#include "Module.h"
#include "Date.h"

using namespace std;

Cashier::Cashier() {
	numOrders = 0;
	count = 0;
}
Cashier::~Cashier() {
	
}

// setters and getters
void Cashier::setNumOrders(int num) {
	numOrders = num;
}

int Cashier::getNumOrders() const {
	return numOrders;
}

void Cashier::setCount(int c) {

	count = c;
}
int Cashier::getCount() const {

	return count;
}

void Cashier::module(BookInfo book[], int SIZE)
{
	const int ARRSIZE = 30;
	
	int orderIndices[ARRSIZE] = { 0 };
	int orderQuantity[ARRSIZE] = { 0 };

	// get date
	int bkDay;
	int bkMon;
	int bkYear;
	// Display
	cout << "\nEnter the day for date added: ";
	cin >> bkDay;

	cout << "\nEnter the month for date added: ";
	cin >> bkMon;

	cout << "\nEnter the year for date added: ";
	cin >> bkYear;
	Date date(bkDay, bkMon, bkYear);

	// display menu
	int menuchoice = 0;
	while (menuchoice != 4)
	{
		cout << "\n\t\t Serendipity BookSellers \t\t\n";
		cout << "\n\t\t   Cashier Menu \t\t\n";
		cout << " 1. Add a book to Cart \n";
		cout << " 2. Edit Cart \n";
		cout << " 3. Checkout \n";
		cout << " 4. Return to the Main Menu\n";
		cout << endl;

		cout << " Enter your Choice : ";
		cin >> menuchoice;

		//Validate input
		while (menuchoice < 1 || menuchoice > 4)
		{
			cout << "\nPlease enter a valid choice in the range of 1 - 5. \n ";
			cout << " Enter your Choice : ";
			cin >> menuchoice;
		}

		switch (menuchoice)
		{
		case 1:
			addToCart(book, SIZE, orderIndices, orderQuantity, count, numOrders);
			break;
		case 2:
			editCart(book, SIZE, orderIndices, orderQuantity, numOrders);
			break;

		case 3:
			checkout(book, SIZE, numOrders, orderIndices, orderQuantity, date);
			break;
		case 4:
			cout << "You selected item 4. \n";
			break;
		default:
			cout << "Please make a valid choice" << endl;

		}

	}
}


void Cashier::addToCart(BookInfo book[], int SIZE, int orderIndices[], int orderQuantity[], int count, int numOrders) {


	int transIndex;
	string transISBN;
	int transQuantity;
	int neededQuantity;
	int oIndex;
	char choice = 'Y';
	char option;

	do {

		// get ISBN
		cout << "\nEnter ISBN: ";
		cin >> transISBN;
		cin.ignore();


		// search for ISBN
		transIndex = searchForISBN(transISBN, book, SIZE);
		
		// ISBN not found
		if (transIndex == -1) {
			cout << "\nThis ISBN was not found in our inventory." << endl;
			cout << "\nEnter another ISBN? (Y/N): ";
			cin >> choice;
			cin.ignore();

		}
		// ISBN found
		else if (transIndex != -1) {

			// get quantity of book
			transQuantity = book[transIndex].getQtyOnHand();
			// search for index in array of indices
			oIndex = findIndex(transIndex, orderIndices, SIZE);
			
			// if book is already in cart, display message
				// ask for another ISBN
			if ((transIndex == 0 && orderQuantity[oIndex] != 0) || (transIndex > 0 && oIndex != -1)) {

				cout << "\nThis book is already in your cart!" << endl;
				cout << "\nUse the <2.Edit Cart> option to change the quantity." << endl;
				cout << "\nEnter a different ISBN? (Y/N): ";
				cin >> choice;
				cin.ignore();

			}
			// if book qty on hand is zero, ask for another ISBN
			else if (transQuantity == 0) {

				cout << "\nThis book is out of stock!" << endl;
				cout << "\nEnter another ISBN? (Y/N): ";
				cin >> choice;
				cin.ignore();
			}

			// elso ask for quantity needed
			else if (transQuantity > 0) {

				cout << "\nEnter the quantity needed: ";
				cin >> neededQuantity;
				cin.ignore();

				// if qty needed is more than available, display message
					// ask for modified quantity
				if (neededQuantity > transQuantity) {

					cout << "\nInsufficient quantity in inventory." << endl;
					cout << "\nWe have " << book[transIndex].getQtyOnHand() << " quantities on hand";
					cout << "\n\nWould you like to modify the quantity needed? (Y/N) : ";
					cin >> option;
					cin.ignore();
					if (option == 'Y') {
						cout << "\nEnter the new quantity needed: ";
						cin >> neededQuantity;
					}

				}
				// if qty needed available, put book info in arrays
				if (neededQuantity <= transQuantity) {
					numOrders++;
					// add index to order
					orderIndices[count] = transIndex;
					orderQuantity[count] = neededQuantity;

					// increment count
					count++;
					// Subtract quantity on hand
					book[transIndex].setQtyOnHand(transQuantity - neededQuantity);

				}


				//reset transQuantity
				transQuantity = 0;
				// ask if another transaction is needed
				choice = addOrder();
			}
		}
		
	} while (choice == 'Y' || choice == 'y');


	setNumOrders(numOrders);
	
	setCount(count);
	
}

void Cashier::editCart(BookInfo book[], int SIZE, int orderIndices[], int orderQuantity[], int numOrders) {

	string transISBN;
	int transIndex;
	int appqty;
	int appindex;
	char option;
	int origqty;


	//get ISBN
	cout << "\nEnter ISBN: ";
	cin >> transISBN;
	cin.ignore();

	// search for index
	transIndex = searchForISBN(transISBN, book, SIZE);
	appindex = findIndex(transIndex, orderIndices, SIZE);

	// if ISBN not found in cart, ask for another try
	if ((transIndex == -1 || appindex == -1) || ((transIndex != -1 || appindex != -1) && orderQuantity[appindex] == 0)) {
		cout << "\nThis ISBN was not found in your cart. Would you like to try again?(Y/N) : ";
		cin >> option;
		cin.ignore();
		if (option == 'Y' || option == 'y') {

			cout << "\nEnter the ISBN: ";
			cin >> transISBN;
			cin.ignore();
			// look for new isbn
			transIndex = searchForISBN(transISBN, book, SIZE);
			appindex = findIndex(transIndex, orderIndices, SIZE);
		}
	}
	// if ISBN is found, get new quantity needed
	if (transIndex != -1 && appindex != -1) {
		origqty = orderQuantity[appindex];
		// get new quantity
		cout << "\nYour cart contains " << orderQuantity[appindex] << " copies of this book.";
		cout << "\nEnter the new quantity: ";
		cin >> appqty;

		// if new quantity needed is more than available, ask for modified qty
		if (book[transIndex].getQtyOnHand() + orderQuantity[appindex] < appqty) {
			
			cout << "\nInsufficient quantity in inventory." << endl;
			cout << "\n\nWe have " << book[transIndex].getQtyOnHand() << " more quantities on hand";
			cout << "\nWould you like to modify the quantity needed? (Y/N) : ";
			cin >> option;
			cin.ignore();
			if (option == 'Y') {
				cout << "\nEnter the new quantity: ";
				cin >> appqty;
			}
		}
		// if qty is available, modify order
		if (book[transIndex].getQtyOnHand() + orderQuantity[appindex] >= appqty) {

			book[transIndex].setQtyOnHand((origqty + book[transIndex].getQtyOnHand()) - appqty);
			orderQuantity[appindex] = appqty;
			cout << "\nThere are now " << orderQuantity[appindex] << " copies of " << transISBN << " in your cart." << endl;
		}
	}

}
void Cashier::checkout(BookInfo book[], int SIZE, int numOrders, int orderIndices[], int orderQuantity[], Date date) {
	const int ARRSIZE = 30;
	double orderTotals[ARRSIZE];
	double orderTotal = 0.0;
	double tax = 0.0;
	double subtotal = 0.0;
	double sales_tax = 0.09;

	// Calculations

	if (numOrders != 0) {
		for (int i = 0; i < numOrders; i++) {
			if (orderQuantity[i] != 0) {

				// total for each title
				orderTotals[i] = calcTotal(book[orderIndices[i]].getRetailPrice(), orderQuantity[i]);
				
				//subtotal
				subtotal = calcSubtotal(orderTotals, numOrders);
				
				// tax
				tax = calcTax(subtotal, sales_tax);
				
				// final total
				orderTotal = calcOrderTotal(subtotal, tax);
				
			}
		}

		// display report
		cout << "\n\t\t Serendipity Booksellers \n\n ";
		cout << " Date: " << date << endl;

		cout << "\n Qty\tISBN\t\tTitle\t\t\t\t\t\t\t     Price\t    Total\n";
		cout << "____________________________________________________________________________________________________________\n\n";


		for (int i = 0; i < numOrders; i++) {
			if (orderQuantity[i] != 0) {
				std::cout << " " << orderQuantity[i] << "\t";
				std::cout << std::left << std::setw(14) << book[orderIndices[i]].getisbn() << "\t";
				std::cout << std::left << std::setw(55) << book[orderIndices[i]].getTitle() << "\t";
				std::cout << std::fixed << std::showpoint << std::right << std::setprecision(2);
				std::cout << std::setw(10) << book[orderIndices[i]].getRetailPrice() << "\t";
				std::cout << std::setw(10) << orderTotals[i] << "\n\n" << std::endl;

				orderIndices[i] = 0;
				orderQuantity[i] = 0;
			}
		}

		cout << " \n\n\n\n";
		cout << " \t\t\tSubtotal\t";
		std::cout << std::left << std::setw(6) << subtotal << std::endl;
		std::cout << "\n\t\t\tTax\t\t";
		std::cout << std::left << std::setw(6) << tax << std::endl;
		cout << " \n\t\t\tTotal\t\t";
		std::cout << std::left << std::setw(6) << orderTotal << std::endl;
		cout << "\n\n  Thank you for shopping at Serendipity BookSellers!\n\n";

		setNumOrders(0);
		
		setCount(0);
		
	}

	
}

//confirming a new transaction
char Cashier::addOrder() {

	char option;
	std::cout << "\nAdd another book to the order?(Y/N): ";
	std::cin >> option;

	return option;

}

// total for each title
double Cashier::calcTotal(double price, int count) {

	double total = count * price;

	return total;
}

// Subtotal for entire order
double Cashier::calcSubtotal(double total[], int count) {

	double subtotal = 0.0;;
	for (int i = 0; i < count; i++) {

		subtotal += total[i];

	}

	return subtotal;
}

// calculate tax
double Cashier::calcTax(double subtotal, double salestax) {

	double tax = subtotal * salestax;
	return tax;
}

// calculate order total

double Cashier::calcOrderTotal(double subtotal, double tax) {

	double orderTotal = subtotal + tax;

	return orderTotal;
}