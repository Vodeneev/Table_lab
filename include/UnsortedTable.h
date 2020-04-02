#include "Table.h"

class UnsortedTable : public Table
{
	P* Arr;
	int size;
	P* end;
	int counter = 1;

public:

	UnsortedTable(int _size) {
		Arr = new P[_size];
		end = Arr;
		size = _size;
	}

	UnsortedTable() {
		Arr = new P[1];
		end = Arr;
		size = 1;
	}

	void Insert(P a) override
	{
		if ((end - Arr) < size - 1) {
			a.id = counter;
			counter++;
			*end = a;
			end++;
		}
		else {
			P* Tmp = new P[size + size / 3 + 1];
			for (int i = 0; i < size; ++i)
				Tmp[i] = Arr[i];
			delete[] Arr;
			Arr = Tmp;
			end = Arr + size - 1;
			a.id = counter;
			counter++;
			*end = a;
			end++;
			size = size + size / 3 + 1;
		}
	}
	P search(int _id) override
	{
		int i = 0;
		while (i < size) {
			if (Arr[i].id == _id) {
				return Arr[i];
			}
			else {
				i++;
			}
		}
	}
	void Remove(int _id) override
	{
		if (size <= 1)
			throw 0;
		else {
			int i = 0;
			while (i < size) {
				if (Arr[i].id == _id) {
					Arr[i] = *(end - 1);
					Arr[i].id = _id;
					end--;
					counter--;
					break;
				}
				else {
					i++;
				}
			}
		}
	}

	int Size() {
		return size;
	}

	P pop() {
		return *(end - 1);
	}
	P Begin() {
		return *Arr;
	}
};

