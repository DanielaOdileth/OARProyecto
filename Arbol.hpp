#pragma once
#include <string>
#include <vector>
#include "NodoPrincipal.hpp"
#include "NodoA.hpp"

class Arbol{
	NodoPrincipal padre;
	NodoA hijos;

public:
	Arbol();
	Arbol(NodoPrincipal padre, NodoA hijos);
	Arbol(const Arbol&);
	~Arbol();
	NodoPrincipal getPadre();
	NodoA getHijos();
	void setPadre(NodoPrincipal nuevo);
	void setHijos(NodoA nhijos);
	void Agregar(Arbol arbol, Nodo nuevo);
	Nodo Buscar(Arbol arbol, int buscar);
};