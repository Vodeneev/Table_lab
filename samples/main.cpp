#include "Table.h"
#include "UnsortedTable.h"
#include "HashTable.h"

int main() 
{
	P a,b;
	a.id = 3;
	b.id = 6;

	HashTable table;
	table.Insert(a);
	table.Insert(b);
	cout << table;
	cout << table.Get_el(3);
	
}