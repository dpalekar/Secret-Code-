#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "BookData.h"
#include <string>
#include "BookInfo.h"
#include <iostream>
using namespace std;

//Default Constructor
BookInfo::BookInfo() : BookData(), Date()
{
	title = "";
	author = "";
	publisher = "";
}

//Constructor
BookInfo::BookInfo(string bkISBN, double wp, int units, double rp, int d, int m, int y, string bkTitle, string bkAuthor, string bkPublisher) : BookData(bkISBN, wp, units, rp), Date(d, m, y)
{
	title = bkTitle;
	author = bkAuthor;
	publisher = bkPublisher;
}

// Destructor
BookInfo::~BookInfo() {}

// Overloaded operator fxn
ostream& operator << (ostream &output, const BookInfo& indBook) {
	output << indBook.getisbn();
	output << ',';
	output << indBook.getWholesalePrice();
	output << ',';
	output << indBook.getQtyOnHand();
	output << ',';
	output << indBook.getRetailPrice();
	output << ',';
	output << indBook.getDay();
	output << ',';
	output << indBook.getMonth();
	output << ',';
	output << indBook.getYear();
	output << ',';
	output << indBook.title;
	output << ',';
	output << indBook.author;
	output << ',';
	output << indBook.getPublisher();
	output << '\n';


	return output;
}


//Accessors
string BookInfo::getTitle() const
{
	return title;
}

string BookInfo::getAuthor() const
{
	return author;
}

string BookInfo::getPublisher() const
{
	return publisher;
}
