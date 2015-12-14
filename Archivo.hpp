#pragma once
#include <string>
#include <vector>
#include "Indice.hpp"
#include "Header.hpp"
#include "Registro.hpp"
#include "Arbol.hpp"

using std::string;
using std::vector;

class Archivo{
	vector<string> lista_registro;
	int availList[];
	Arbol arbol;
	Header header;
	Indice indice_a;
	string nombre;

public:
	Archivo();
	Archivo(vector<string> lista_registro, int availList[], Arbol arbol, Header header, Indice indice_a, string nombre);
	Archivo(const Archivo&);
	~Archivo();
	const vector<string> getLista();
	const Indice getIndice();
	const string getNombre();
	const Header getHeader();
};