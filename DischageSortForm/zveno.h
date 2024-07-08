#pragma once


class zveno {
private:
	int info;
	zveno* next;
public:
	zveno(int info = 0) {
		this->info = info;
		next = nullptr;
	}
	~zveno() {
		next = 0;
	}
	zveno(const zveno& tmp) {
		info = tmp.info;
		next = 0;
	}
	zveno& operator=(zveno tmp) {
		info = tmp.info;
		return *this;
	}
	int getInfo() {
		return info;
	}
	zveno* getNext() {
		return next;
	}
	void setInfo(int val) {
		info = val;
	}
	void setNext(zveno* tmp) {
		next = tmp;
	}
};