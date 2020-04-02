#include "gtest.h"
#include "Monom.h"
#include "List.h"
#include "Polinom.h"
#include "Table.h"
#include "UnsortedTable.h"
#include "SortedTable.h"
#include "HashTable.h"

TEST(UnsortedTable, can_insert_el_1) {
	Polinom p1;
	List<Monom> l1;
	int coeff_res;
	string a = "1+x^2";
	Polinom aa;
	aa.toPolinom(a);
	UnsortedTable R;
	P res;
	res.el = aa;
	R.Insert(res);
	p1 = R.pop().el;
	l1 = p1.Head();
	coeff_res = l1.head->data.coeff;
	EXPECT_EQ(coeff_res, 1);
}

TEST(UnsortedTable, can_insert_el_2) {
	P a, b;
	UnsortedTable R;
	R.Insert(a);
	R.Insert(b);
	EXPECT_EQ(R.Size(), 3);
}

TEST(UnsortedTable, can_insert_el_3) {
	P a, b;
	UnsortedTable R;
	R.Insert(a);
	R.Insert(b);
	EXPECT_EQ(R.pop().id, 2);
}

TEST(UnsortedTable, can_remove_el_1) {
	Polinom p1;
	List<Monom> l1;
	int coeff_res;
	string a = "1+x^2";
	string b = "2+x^2";
	Polinom aa, bb;
	aa.toPolinom(a);
	bb.toPolinom(b);
	UnsortedTable R;
	P res, res1;
	res.el = aa;
	res1.el = bb;
	R.Insert(res);
	R.Insert(res1);
	R.Remove(2);
	p1 = R.pop().el;
	l1 = p1.Head();
	coeff_res = l1.head->data.coeff;
	EXPECT_EQ(coeff_res, 1);
}

TEST(UnsortedTable, can_remove_el_2) {
	Polinom p1;
	List<Monom> l1;
	int coeff_res;
	string a = "1+x^2";
	string b = "2+x^2";
	Polinom aa, bb;
	aa.toPolinom(a);
	bb.toPolinom(b);
	UnsortedTable R;
	P res, res1;
	res.el = aa;
	res1.el = bb;
	R.Insert(res);
	R.Insert(res1);
	R.Remove(1);
	p1 = R.Begin().el;
	l1 = p1.Head();
	coeff_res = l1.head->data.coeff;
	EXPECT_EQ(coeff_res, 2);
}


TEST(SortedTable, can_insert_el_1) {
	SortedTable res(5);
	P a;
	a.id = 3;
	res.Insert(a);
	EXPECT_EQ(res.Get_el(0).id , 3);
}

TEST(SortedTable, can_insert_el_2) {
	SortedTable res(5);
	P a,b;
	a.id = 3;
	b.id = 4;
	res.Insert(a);
	res.Insert(b);
	EXPECT_EQ(res.Get_el(1).id, 4);
}

TEST(SortedTable, can_insert_el_3) {
	SortedTable res(5);
	P a, b;
	a.id = 3;
	b.id = 1;
	res.Insert(a);
	res.Insert(b);
	EXPECT_EQ(res.Get_el(0).id, 1);
}

TEST(SortedTable, can_Remove_1) {
	SortedTable res(5);
	P a, b;
	a.id = 3;
	b.id = 1;
	res.Insert(a);
	res.Insert(b);
	res.Remove(1);
	EXPECT_EQ(res.Get_el(0).id, 3);
}
