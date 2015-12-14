#pragma once
#include <string>
#include <vector>
#include "Nodo.hpp"

using std::string;
using std::vector;

class NodoPrincipal{
	Nodo n1;
	Nodo n2;
	Nodo n3;
	Nodo n4;
	Nodo n5;
	Nodo n6;

public:
	NodoPrincipal();
	NodoPrincipal(Nodo n1, Nodo n2, Nodo n3, Nodo n4, Nodo n5, Nodo n6);
	NodoPrincipal(const NodoPrincipal&);
	~NodoPrincipal();
	Nodo getNodos(int numero);
	void setNodo(int numero, Nodo n);
};