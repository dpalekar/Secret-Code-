#ifndef CASHIER_H
#define CASHIER_H

#include "BookData.h"
#include "BookInfo.h"
#include "BookData.h"
#include "templatefxns.h"
#include "searchfor.h"
//#include "InventoryMenu.h"
#include "Module.h"
#include "Date.h"
class Cashier : public Module {

private:

	int numOrders;
	int count;
public:

	// default constructor
	Cashier();
	// default destructor
	~Cashier();

	// setter and getter for numOrders
	void setNumOrders(int num);
	int getNumOrders() const;

	//setter and getter for count
	void setCount(int c);
	int getCount() const;

	void module(BookInfo book[], const int SIZE);
	double calcTotal(double price, int count);
	double calcSubtotal(double total[], int count);
	double calcTax(double subtotal, const double TAX);
	double calcOrderTotal(double subtotal, double tax);
	char addOrder();
	void addToCart(BookInfo book[], int SIZE, int orderIndices[], int orderQuantity[], int count, int numOrders);
	void editCart(BookInfo book[], int SIZE, int indices[], int qty[], int numOrders);
	void checkout(BookInfo book[], int SIZE, int numOrders, int orderIndices[], int orderQuantity[], Date date);


};

#endif
