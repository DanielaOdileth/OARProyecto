#pragma once
#include <string>
#include <vector>
#include "Nodo.hpp"
#include "NodoPrincipal.hpp"

using std::string;
using std::vector;

class NodoA{
	NodoPrincipal hijo_der;
	NodoPrincipal hijo_izq;

public:
	NodoA();
	NodoA(NodoPrincipal hijo_der, NodoPrincipal hijo_izq);
	NodoA(const NodoA&);
	~NodoA();
	NodoPrincipal getHijo_der();
	NodoPrincipal getHijo_izq();
	void setHijo_der(NodoPrincipal hijo_der);
	void setHijo_izq(NodoPrincipal hijo_izq);
};