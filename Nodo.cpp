#include <string>
#include <sstream>
#include <vector>
#include "Nodo.hpp"

using namespace std;

Nodo::Nodo(){
	RRN = -1;
	llave = -1;
}

Nodo::Nodo(int RRN, int llave){
	this->RRN = RRN;
	this->llave = llave;
}

Nodo::Nodo(const Nodo& other){
	RRN = other.RRN;
	llave = other.llave;
}
Nodo::~Nodo(){
	
}

const int Nodo::getRRN()const{
	return RRN;
}

const int Nodo::getLlave()const{
	return llave;
}

void Nodo::setRRN(int RRN){
	this->RRN = RRN;
}

void Nodo::setLlave(int llave){
	this->llave = llave;
}