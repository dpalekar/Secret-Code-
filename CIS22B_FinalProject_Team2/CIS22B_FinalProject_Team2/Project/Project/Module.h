#pragma once
#ifndef MODULE_H
#define MODULE_H
#include "BookInfo.h"
using namespace std;

class Module {


public:
	// default constructor
	Module();

	// destructor
	virtual ~Module();

	virtual void module(BookInfo book[], const int SIZE);

};

#endif