#pragma once
#include "Tqueue.h"
#include <string>
#include <iostream>
using namespace std;

class Sort {
private:
	Tqueue* Och;
	int size, max_num_dig, val, flag;
	int* mem;
	string mark;
public:
	Sort(int* mas, int size) {
		Och = new Tqueue[10];
		this->size = size;
		mem = new int[size];
		max_num_dig = 0;
		for (int i = 0; i < size; i++) {
			flag = mas[i];
			val = 0;
			while (flag) {
				flag /= 10;
				val++;
			}
			if (val > max_num_dig) {
				max_num_dig = val;
			}
			mem[i] = mas[i];
		}
	}
	~Sort() {
		delete[]mem;
		delete[]Och;
	}
	Sort& operator=(Sort tmp) {
		if (size != 0) {
			delete[]mem;
		}
		Och = new Tqueue[10];
		size = tmp.size;
		mem = new int[tmp.size];
		max_num_dig = tmp.max_num_dig;
		for (int i = 0; i < size; i++) {
			mem[i] = tmp.mem[i];
		}
		return *this;
	}
	void step1(int k) {
		if (k < max_num_dig) {
			for (int i = 0; i < size; i++) {
				flag = mem[i];
				val = 0;
				while (flag) {
					flag /= 10;
					val++;
				}
				if (val <= k) {
					Och[0].push(mem[i]);
				}
				else {
					mark = to_string(mem[i])[val - k - 1];
					flag = stoi(mark);
					Och[flag].push(mem[i]);
				}
			}
		}
	}
	void step2() {
		flag = 0;
		for (int i = 0; i < 10; i++) {
			while (!Och[i].is_empty()) {
				mem[flag++] = Och[i].pop();
			}
		}
	}
	void allStep() {
		for (int i = 0; i < max_num_dig; i++) {
			step1(i);
			step2();
		}
	}
	int* GetMem() {
		return mem;
	}
	Tqueue GetOchered(int k) {
		return Och[k];
	}
};