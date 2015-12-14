#include <vector>
#include <string>
#include "NodoPrincipal.hpp"

using std::vector;
using std::string;

NodoPrincipal::NodoPrincipal(){

}
NodoPrincipal::NodoPrincipal(Nodo n1, Nodo n2, Nodo n3, Nodo n4, Nodo n5, Nodo n6){
	this->n1 = n1;
	this->n2 = n2;
	this->n3 = n3;
	this->n4 = n4;
	this->n5 = n5;
	this->n6 = n6;
}
NodoPrincipal::NodoPrincipal(const NodoPrincipal& other){
	n1 = other.n1;
	n2 = other.n2;
	n3 = other.n3;
	n4 = other.n4;
	n5 = other.n5;
	n6 = other.n6;
}
NodoPrincipal::~NodoPrincipal(){

}
Nodo NodoPrincipal::getNodos(int numero){
	if(numero == 1){
		return n1;
	}
	if(numero == 2){
		return n2;
	}
	if(numero == 3){
		return n3;
	}
	if(numero == 4){
		return n4;
	}
	if(numero == 5){
		return n5;
	}
	if(numero == 6){
		return n6;
	}
}
void NodoPrincipal::setNodo(int numero, Nodo n){
	if(numero == 1){
		this->n1 = n;
	}
	if(numero == 2){
		this->n2 = n;
	}
	if(numero == 3){
		this->n3 = n;
	}
	if(numero == 4){
		this->n4 = n;
	}
	if(numero == 5){
		this->n5 = n;
	}
}