#ifndef INVENTORYMENU_H
#define INVENTORYMENU_H
#include "BookInfo.h"
#include "Module.h"

class Inventory : public Module {

public:
	// Default constructor
	Inventory();
	// Destructor
	~Inventory();
	void module(BookInfo book[], int SIZE);
	void lookUpBook(BookInfo book[], int SIZE);
	void editBook(BookInfo book[], int SIZE);
	void addBook(BookInfo book[], int SIZE);
	void deleteBook(BookInfo book[], int SIZE);



};
#endif
