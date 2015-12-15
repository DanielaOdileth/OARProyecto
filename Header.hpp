#pragma once
#include <string>
#include <vector>
#include "Campo.hpp"

using std::vector;
using std::string;

class Header{
	string nombre_file;
	int size_file;
	vector<Campo> lista_campo;

public:
	Header();
	Header(string nombre_file, vector<Campo> lista_campo);
	Header(const Header&);
	~Header();
	const vector<Campo> getLista_Campo()const;
	const string getNombre_File()const;
	void setNombre_File(string nombre_file);
	void setLista_Campos(vector<Campo>& lista_campo);
	string toString()const;
	string Prueba();
};