#include <string>
#include <vector>
#include <sstream>
#include "Header.hpp"

using namespace std;

Header::Header(){
	nombre_file = "";
	//size_file = 0;
}
Header::Header(string nombre_file, vector<Campo> lista_campo){
	this->nombre_file = nombre_file;
	//this->size_file = size_file;
}
Header::Header(const Header& other){
	nombre_file = other.nombre_file;
	//size_file = other.size_file;
}
Header::~Header(){
}
	
const vector<Campo> Header::getLista_Campo()const{
	return lista_campo;
}

const string Header::getNombre_File()const{
	return nombre_file;
}

/*const int Header::getSize_File() const{
	return size_file;
}*/
	
void Header::setNombre_File(string nombre_file){
	this->nombre_file = nombre_file;
}
/*void Header::setSize_File(int size_file){
	this->size_file = size_file;
}*/
void Header::setLista_Campos(vector<Campo>& lista_campo){
	for(int i = 0; i < lista_campo.size(); i++){
		this->lista_campo[i] = lista_campo[i];
	}

}

string Header::toString()const{
	stringstream s;
	s << " " << nombre_file << ":";

	for(int i = 0; i < lista_campo.size(); i++){
		s << lista_campo[i].getNombre() << "[" << lista_campo[i].getSize() << "] ";
	}
	return s.str();
}