#include "Table.h"
#include "ListWithoutHead.h"
#define N 10

int Hash_function(int _id, int _size)
{
	int index;
	index = _id % (_size / 2);
	return index;
}

class HashTable : public Table
{
	ListWithoutHead<P>* Arr;
	int size;

public:
	HashTable() 
	{
		Arr = new ListWithoutHead<P>[N];
		size = N;
	}

	HashTable(int _size)
	{
		Arr = new ListWithoutHead<P>[_size];
		size = _size;
	}

	void Realloc()
	{
		ListWithoutHead<P>* Tmp = new ListWithoutHead<P>[size + size / 3 + 1];
		for (int i = 0; i < size; ++i)
			Tmp[i] = Arr[i];
		delete[] Arr;
		Arr = Tmp;
		size = size + size / 3 + 1;
	}

	void Insert(P a) override
	{
		int index;
		index = Hash_function(a.id,size);
		Node<P>* En;
		En = Arr[index].End();
		Arr[index].insert(a,En);
	}

	virtual void Remove(int _id) override
	{
		int index;
		index = Hash_function(_id, size);
		Arr[index].delete_key(_id);
	}

	virtual P search(int _id) override
	{
		int index;
		index = Hash_function(_id, size);
		P res;
		res = Arr[index].search_key(_id);
		return res;
	}

	ListWithoutHead<P> Get_el(int _i) 
	{
		return Arr[_i];
	}

	friend ostream& operator<<(ostream& out, HashTable& v) // печать ключей
	{
		for (int i = 0; i < (v.size/2); i++)
			out << v.Arr[i].Head()->data.id << endl;
		return out;
	}

};
