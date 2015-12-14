#include <string>
#include <sstream>
#include "Campo.hpp"

using namespace std;

Campo::Campo(){
	nombre = " ";
	tipo = "";
	size = 0;
	size_dec = 0;
	key = false;
}

Campo::Campo(string nombre, string tipo, int size, int size_dec, bool key){
	this->nombre = nombre;
	this->tipo = tipo;
	this->size = size;
	this->size_dec = size_dec;
	this->key = key;
}

Campo::Campo(const Campo& other){
	nombre = other.nombre;
	tipo = other.tipo;
	size = other.size;
	size_dec = other.size_dec;
	key = other.key;
}

Campo::~Campo(){
}

const string Campo::getNombre()const{
	return nombre;
}
	
const string Campo::getTipo() const{
	return tipo;
}

const int Campo::getSize() const{
	return size;
}
	
const int Campo::getSize_dec() const{
	return size_dec;
}
	
const bool Campo::getKey() const{
	return key;
}

void Campo::setNombre(string nombre){
	this->nombre = nombre;
}
	
void Campo::setTipo(string tipo){
	this->tipo = tipo;
}
	
void Campo::setSize(int size){
	this->size = size;
}
	
void Campo::setSize_dec(int size_dec){
	this->size_dec = size_dec;
}

void Campo::setKey(bool key){
	this->key = key;
}

/*void Campo::removeCampo(int posicion){
	datos_campo.erase(datos_campo.begin()+posicion);
} colocar en la clase de registro*/