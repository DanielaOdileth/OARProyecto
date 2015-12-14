#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

class Nodo{
	int RRN;
	int llave;

public:
	Nodo();
	Nodo(int RRN, int llave);
	Nodo(const Nodo&);
	~Nodo();
	const int getRRN()const;
	const int getLlave()const;
	void setRRN(int RRN);
	void setLlave(int llave);
	string toString()const;
};