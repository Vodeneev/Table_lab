#pragma once
#include "Table.h"

class SortedTable : public Table
{
	P* Arr;
	int size;
	int end;

public:

	SortedTable(int _size) {
		Arr = new P[_size];
		end = 0;
		size = _size;
	}

	SortedTable() {
		Arr = new P[15];
		end = 0;
		size = 15;
	}

	void Insert(P a) override
	{
		if (a.id == search(a.id).id)
			throw 0;
		else
		{
			if (end >= size - 1) {
				P* Tmp = new P[size + size / 3 + 1];
				for (int i = 0; i < size; ++i)
					Tmp[i] = Arr[i];
				delete[] Arr;
				Arr = Tmp;
				size = size + size / 3 + 1;
			}
			int i = 0;
			while (a.id > Arr[i].id&& i != end) {
				i++;
			}
			for (int k = end; k > i; k--)
				Arr[k] = Arr[k - 1];
			Arr[i] = a;
			end++;
		}

	}

	void Remove(int _id) override
	{
		if (size <= 1)
			throw 0;
		else 
		{
			int it = search_index(_id);
			for (int k = it; k < end + 1; k++)
				Arr[k] = Arr[k + 1];
			end--;
		}
	}

	P search(int _id) override
	{
		int i = 0;
		while (i < end) {
			if (Arr[i].id == _id) {
				return Arr[i];
			}
			else
				i++;
		}
		P a;
		a.id = 0;
		return a;
	}

	int search_index(int _id)
	{
		int i = 0;
		while (i < end) {
			if (Arr[i].id == _id) {
				return i;
			}
			else
				i++;
		}
		return -1;
	}

	P Get_el(int _i) {
		return Arr[_i];
	}

	friend ostream& operator<<(ostream& out, SortedTable& v) // печать ключей
	{
		for (int i = 0; i < v.end; i++)
			out << v.Arr[i].id;
		return out;
	}
};

