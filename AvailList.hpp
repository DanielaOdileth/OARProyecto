#pragma once
#include <string>

using std::string;

class AvailList{
	int referencia;
	int cantidad;

public:
	AvailList();
	AvailList(int referencia);
	AvailList(const AvailList&);
	~AvailList();
	const int pop(int cantidad);
	void push(int referencia);
	const int getSize();
	const int isEmpty();
	/*AvailList();
	AvailList(int referencia);
	AvailList(const AvailList&);
	~AvailList();*/
	/*const int pop();
	const int getSize();
	void push(int value);
	const int isEmpty();*/
};