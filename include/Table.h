#pragma once
#include "Polinom.h"

struct P {
	int id;
	Polinom el;
};

class Table
{
public:

	virtual void Insert(P a) = 0;
	virtual void Remove(int _id) = 0;
	virtual P search(int _id) = 0;
};

