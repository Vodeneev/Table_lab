#pragma once
#include"iostream"
#include "Iterator.h"
#include "Monom.h"

using namespace std;
template <typename T>

class ListWithoutHead
{
	Node<T>* head;
	int size;
public:

	ListWithoutHead()
	{
		head = new Node<T>;
		head->next = NULL;
		size = 0;
	}

	ListWithoutHead(int n) {
		head = new Node<T>;
		size = n;
		Node<T>* tmp = head;
		for (int i = 0; i < n; i++) {
			Node<T>* tmp2 = new Node<T>;
			tmp->next = tmp2; 
			tmp = tmp2; 
		}
	}
	void insert(T data, Node<T>* prev) {
		if (size == 0)
		{
			head->data = data;
			size++;
		}
		else
		{
			Node<T>* a = new Node<T>;
			a->data = data;
			Node<T>* b = prev->next;
			prev->next = a;
			a->next = b;
			size++;
		}
	}

	int Size()
	{
		return size;
	}

	Node<T>* Head() 
	{
		return head;
	}

	Node<T>* End() 
	{
		Node<T>* a = head;
		while (a->next != NULL)
		{
			a = a->next;
		}
		return a;
	}

	Iterator<T> begin() {
		Iterator i(head);
		return i;
	}

	Iterator<T> end() {
		int k = 0;
		Iterator i(head);
		while (k != size) {
			++i;
			k++;
		}
		return i;
	}
	void Delete(Node<T>* i) {
		if (i == head) {
			Node<T>* b = head->next;
			delete head;
			head = b;
			size--;
		}
		else {
			if (i->next->next != NULL) {
				Node<T>* a = i->next->next;
				delete i->next;
				i->next = a;
				size--;
			}
			else {
				delete i->next;
				size--;
			}
		}
	}
	int& Getelem(Node<T>* i) {
		return i->data;
	}

	void insert_front(T _data)
	{
		Node<int>* a = new Node<int>;
		a->data = _data;
		Node<int>* b = head;
		head = a;
		a->next = b;
		size++;
	}

	Node<P>* search_prevkey(int _id)
	{
		Node<P>* a = head;
		if (a->data.id == _id)
			return NULL;
		else
		{
			while (a->next->data.id != _id && a->next != NULL) {
				a = a->next;
			}
			if (a->next == NULL)
				throw 0;
			else
				return a;
		}
	}

	P search_key(int _id)
	{
		Node<P>* a = head;
			while (a->data.id != _id && a != NULL)
			{
				a = a->next;
			}
			if (a == NULL)
				throw 0;
			else
				return a->data;
	}

	void delete_key(int _id)
	{
		Node<P>* i;
		i = search_prevkey(_id);
		if (i == NULL) {
			Node<P>* b = head->next;
			delete head;
			head = b;
			size--;
		}
		else {
			if (i->next->next != NULL) {
				Node<P>* a = i->next->next;
				delete i->next;
				i->next = a;
				size--;
			}
			else {
				delete i->next;
				i->next = NULL;
				size--;
			}
		}

	}

	friend istream& operator>>(istream& in, List<T>& v)
	{
		Node<T>* a = v.Head();
		while (a->next != NULL) {
			in >> a->data;
			a = a->next;
		}
		return in;
	}
	friend ostream& operator<<(ostream& out, ListWithoutHead<P>& v)
	{
		if (v.size == 0)
			throw 0;
		Node<P>* a = v.Head();
		while (a != NULL) {
			out << a->data.id << ' ';
			a = a->next;
		}
		return out;
	}
	~ListWithoutHead() {
		while (head != NULL) {
			Node<T>* a = head->next;
			delete head;
			head = a;
		}
	}
};
