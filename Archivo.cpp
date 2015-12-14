#include <string>
#include <vector>
#include "Archivo.hpp"

using std::string;
using std::vector;

Archivo::Archivo(){

}
Archivo::Archivo(vector<string> lista_registro, int avalList[], Arbol arbol, Header header, Indice a, string nombre){
	//this->header = header;
	//this->availList = availList;
	this->nombre = nombre;
}
Archivo::Archivo(const Archivo& other){
	//header = other.header;
	//availList = other.availList;
	nombre = other.nombre;
}
Archivo::~Archivo(){

}
const vector<string> Archivo::getLista(){
	return lista_registro;
}

const Indice Archivo::getIndice(){
	return indice_a;
}

const string Archivo::getNombre(){
	return nombre;
}
/*const Header Archivo::getHeader()const{
	return header;
}
	
const AvailList Archivo::getAvailList()const{
	return availList;
}*/