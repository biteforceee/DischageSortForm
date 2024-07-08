#pragma once
#include "zveno.h"


class Tqueue {
private:
	zveno* first;
	zveno* last;
public:
	Tqueue() {
		first = 0;
		last = 0;
	}
	~Tqueue() {
		delete first;
	}
	Tqueue(const Tqueue& tmp) {
		if (tmp.first == 0) {
			first = 0;
			last = 0;
		}
		else {
			zveno* current = tmp.first;
			first = new zveno(*current);
			last = first;
			while (current->getNext() != 0) {
				current = current->getNext();
				zveno* A = new zveno(current->getInfo());
				last->setNext(A);
				last = A;
			}
		}
	}
	Tqueue& operator =(Tqueue tmp) {
		if (first != 0) {
			delete first;
		}
		if (tmp.first == 0) {
			first = 0;
			last = 0;
		}
		else {
			zveno* current = tmp.first;
			first = new zveno(*current);
			last = first;
			while (current->getNext() != 0) {
				current = current->getNext();
				zveno* A = new zveno(current->getInfo());
				last->setNext(A);
				last = A;
			}
		}
		return *this;
	}
	void push(int tmp) {
		zveno* A = new zveno(tmp);
		if (first == 0) {
			first = A;
			last = A;
		}
		else {
			last->setNext(A);
			last = A;
		}
	}
	int pop() {
		if (first != 0) {
			int a = first->getInfo();
			zveno* q = first;
			first = first->getNext();
			q->setNext(0);
			delete q;
			if (first == 0) {
				last = 0;
			}
			return a;
		}
		return -1;
	}
	int is_empty() {
		if (first == 0) {
			return 1;
		}
		return 0;
	}
};