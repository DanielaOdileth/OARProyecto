#pragma once
#include <string>
#include <vector>
//#include "AvailList.hpp"
#include "Indice.hpp"
#include "Header.hpp"
#include "Registro.hpp"

using std::string;
using std::vector;

class Archivo{
	vector<string> lista_registro;
	int availList[];
	//Indice indices;
	//Arbol arbol;
	//AvailList availList;
	Header header;
	Indice indice_a;
	string nombre;

public:
	Archivo();
	Archivo(vector<string> lista_registro, int avalList[], Header header, Indice a, string nombre);
	Archivo(const Archivo&);
	~Archivo();
	const vector<string> getLista();
	const Indice getIndice();
	const string getNombre();
	//const Header getHeader()const;
};