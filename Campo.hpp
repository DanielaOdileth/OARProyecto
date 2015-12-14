#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

class Campo {
	//stricadena[30];
	string nombre;
	string tipo;
	int size;
	int size_dec;
	bool key;
	vector<string> datos_campo;

public:
	Campo();
	Campo(string nombre, string tipo, int size, int size_dec, bool key);
	Campo(const Campo&);
	~Campo();
	const string getNombre()const;
	const string getTipo() const;
	const int getSize() const;
	const int getSize_dec() const;
	const bool getKey()const;
	void setNombre(string nombre);
	void setTipo(string tipo);
	void setSize(int size);
	void setSize_dec(int size_dec);
	void setKey(bool key);
	//void CrearCampos(vector<Campo>& campos);
	//void removeCampo(int posicion); colocar en la clase registro
};