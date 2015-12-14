#include <vector>
#include <string>
#include "NodoA.hpp"

using std::vector;
using std::string;

NodoA::NodoA(){

}
NodoA::NodoA(/*Nodo datos, */NodoPrincipal hijo_der, NodoPrincipal hijo_izq){
	//this->datos = datos;
	this->hijo_der = hijo_der;
	this->hijo_izq = hijo_izq;
}
NodoA::NodoA(const NodoA& other){
	//datos = other.datos;
	hijo_der = other.hijo_der;
	hijo_izq = other.hijo_izq;
}
NodoA::~NodoA(){

}
/*const Nodo NodoA::getDatos()const{
	return datos;
}*/
NodoPrincipal NodoA::getHijo_der(){
	return hijo_der;
}
NodoPrincipal NodoA::getHijo_izq(){
	return hijo_izq;
}
/*void NodoA::setDato(Nodo datos){
	this->datos = datos;
}*/
void NodoA::setHijo_der(NodoPrincipal hijo_der){
	this->hijo_der = hijo_der;
}
void NodoA::setHijo_izq(NodoPrincipal hijo_izq){
	this->hijo_izq = hijo_izq;
}
