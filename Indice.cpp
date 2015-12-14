#include <string>
#include <vector>
#include "Indice.hpp"

using std::string;
using std::vector;

Indice::Indice(){
	//n = NULL;
	//next = NULL;
}

Indice::Indice(Nodo n, Nodo next){
	this->n = n;
	this->next = next;
}

Indice::Indice(const Indice& other){
	n = other.n;
	next = other.next;
}

Indice::~Indice(){

}

const Nodo Indice::getN()const{
	return n;
}
	
const Nodo Indice::getNext()const{
	return next;
}

void Indice::setN(Nodo n){
	this->n = n;
}

void Indice::setNext(Nodo next){
	this->next = next;
}
