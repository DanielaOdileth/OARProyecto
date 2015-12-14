#include <string>
#include <sstream>
#include <vector>
#include "Nodo.hpp"

using namespace std;

Nodo::Nodo(){
	RRN = 0;
	llave = 0;
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
/*void Nodo::setNodo(Nodo nodo){
	this->nodo = nodo;
}*/
/*string toString()const{
	stringstream s;
	s << RRN << "  " << llave << "\n";
	return s.str();
}*/