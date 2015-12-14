#pragma once
#include <string>
#include <vector>
#include "Nodo.hpp"
#include "NodoPrincipal.hpp"

using std::string;
using std::vector;

class NodoA{
	//Nodo datos;
	NodoPrincipal hijo_der;
	NodoPrincipal hijo_izq;

public:
	NodoA();
	NodoA(/*Nodo datos, */NodoPrincipal hijo_der, NodoPrincipal hijo_izq);
	NodoA(const NodoA&);
	~NodoA();
	//const Nodo getDatos()const;
	NodoPrincipal getHijo_der();
	NodoPrincipal getHijo_izq();
	//void setDato(Nodo datos);
	void setHijo_der(NodoPrincipal hijo_der);
	void setHijo_izq(NodoPrincipal hijo_izq);
};