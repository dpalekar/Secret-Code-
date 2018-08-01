#pragma once
#ifndef TEMPLATEFXNS_H
#define TEMPLATEFXNS_H

template <typename Type>
Type findIndex(Type var, Type myarray[], Type SIZE) {

	bool found = false;
	int index = 0;

	while (!found && index < SIZE)
	{
		if (myarray[index] == var)
			found = true;
		else
			index++;
	}

	if (found) {
		return index;
	}
	else {
		return -1;
	}
}



#endif /* templatefxns_h */