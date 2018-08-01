#pragma once
#ifndef SEARCHFOR_H
#define SEARCHFOR_H

#include <iostream>
#include "BookInfo.h"
using namespace std;

int searchForISBN(string searchISBN, BookInfo book[], const int ARR_SIZE);
int getIndex(BookInfo book[], const int ARR_SIZE);
void printInfo(BookInfo book[], int index);
#endif /* searchfor_h */