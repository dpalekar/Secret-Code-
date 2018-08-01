#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "BookData.h"

//Default Constructor
BookData::BookData()
{
	isbn = "";
	wholesalePrice = 0.0;
	qtyOnHand = 0;
	retailPrice = 0.0;
}

BookData::BookData(string bkISBN, double wp, int units, double rp)
{
	isbn = bkISBN;
	wholesalePrice = wp;
	qtyOnHand = units;
	retailPrice = rp;
}


void BookData::setQtyOnHand(int qty) {
	qtyOnHand = qty;
}

BookData::~BookData() {}
//Accessors
std::string BookData::getisbn() const
{
	return isbn;
}

double BookData::getWholesalePrice() const
{
	return wholesalePrice;
}

int BookData::getQtyOnHand() const
{
	return qtyOnHand;
}


double BookData::getRetailPrice() const
{
	return retailPrice;
}