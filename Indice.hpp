#pragma once
#include <string>
#include <vector>
#include "Nodo.hpp"

using std::string;
using std::vector;

class Indice{
	Nodo n;
	Nodo next; 

public:
	Indice();
	Indice(Nodo n, Nodo next);
	Indice(const Indice&);
	~Indice();
	const Nodo getN()const;
	const Nodo getNext()const;
	void setN(Nodo n);
	void setNext(Nodo nuevo);
};