#ifndef BOOKDATA_H
#define BOOKDATA_H
#include <string>
using namespace std;

class BookData
{
private:
	string isbn;
	double wholesalePrice;
	int qtyOnHand;
	double retailPrice;

public:
	//Default Constructor
	BookData();

	// Constructor
	BookData(string bkISBN, double wp, int units, double rp);

	//Destructor
	~BookData();

	//Setter
	void setQtyOnHand(int qty);

	//Accessors
	string getisbn() const;

	double getWholesalePrice() const;

	int getQtyOnHand() const;

	double getRetailPrice() const;

};

#endif
