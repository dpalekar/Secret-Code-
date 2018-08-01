#ifndef REPORTS_H
#define REPORTS_H
#include "InventoryMenu.h"
#include "BookInfo.h"
class Reports : public Module {

public:

	// Default Constructor
	Reports();

	// Destructor
	~Reports();

	void module(BookInfo book[], int SIZE);
	void reportInventoryList(BookInfo book[], int SIZE);
	void reportWholesaleValue(BookInfo book[], int SIZE);
	void reportRetailValue(BookInfo book[], int SIZE);
	void reportListByQuantity(BookInfo book[], int SIZE);
	void reportListByCost(BookInfo book[], int SIZE);
	void reportListByAge(BookInfo book[], int SIZE);
	void selectionSort2descending(int array1[], string array2[], int size);
	void selectionSort2descending(double array1[], string array2[], int size);



};


#endif
