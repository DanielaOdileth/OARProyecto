#include <string>
#include <vector>
#include "Registro.hpp"
#include <sstream>

using namespace std;

Registro::Registro(){
	lista = "";
}
Registro::Registro(string lista){
	this->lista = lista;
}
Registro::Registro(const Registro& other){
	lista = other.lista;

}
Registro::~Registro(){

}

const vector<string> Registro::getLista()const{
	return lista_campos;
}
const string Registro::getValor() const{
	return lista;
}

string Registro::getElemento(int posicion){
	return lista_campos[posicion];	
}

void Registro::setElemento(int posicion, string nuevo){
		this->lista_campos[posicion] = nuevo;
}
string Registro::toString(vector<string> lista_campo)const{
	stringstream s;
	for(int i = 0; i < lista_campo.size(); i++){
		s <<" " << lista_campo[i];
	}
	return s.str();
}