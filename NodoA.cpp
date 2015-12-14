#include <vector>
#include <string>
#include "NodoA.hpp"

using std::vector;
using std::string;

NodoA::NodoA(){

}
NodoA::NodoA(NodoPrincipal hijo_der, NodoPrincipal hijo_izq){
	this->hijo_der = hijo_der;
	this->hijo_izq = hijo_izq;
}
NodoA::NodoA(const NodoA& other){
	hijo_der = other.hijo_der;
	hijo_izq = other.hijo_izq;
}
NodoA::~NodoA(){

}
NodoPrincipal NodoA::getHijo_der(){
	return hijo_der;
}
NodoPrincipal NodoA::getHijo_izq(){
	return hijo_izq;
}
void NodoA::setHijo_der(NodoPrincipal hijo_der){
	this->hijo_der = hijo_der;
}
void NodoA::setHijo_izq(NodoPrincipal hijo_izq){
	this->hijo_izq = hijo_izq;
}
