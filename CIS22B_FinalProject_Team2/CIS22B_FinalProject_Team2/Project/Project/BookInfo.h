#ifndef BOOKINFO_H
#define BOOKINFO_H
#include "BookData.h"
#include "Date.h"
#include <string>
using namespace std;

class BookInfo : public BookData, public Date
{
private:
	string title;
	string author;
	string publisher;

public:
	//Default Constructor
	BookInfo();


	//Constructor
	BookInfo(string bkISBN, double wp, int units, double rp, int d, int m, int y, string bkTitle, string bkAuthor, string bkPublisher);

	//Destructor
	~BookInfo();

	//Overloaded operator
	friend ostream& operator << (ostream &output, const BookInfo& indBook);


	//Accessors
	string getTitle() const;

	string getAuthor() const;

	string getPublisher() const;


};


#endif
