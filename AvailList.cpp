#include <string>
#include "AvailList.hpp"

using std::string;
	
//int cantidad;
//int lista[cantidad];

AvailList::AvailList(){
	referencia = -1;
}

AvailList::AvailList(int referencia){
	this->referencia = -1;
}

AvailList::AvailList(const AvailList& other){
	referencia = other.referencia;
}

AvailList::~AvailList(){

}

/*const int AvailList::pop(int cantidad){
	//return lista[cantidad];
}
void AvailList::push(int referencia){
	/*lista[cantidad] = referencia;
	cantidad++;
}*/

//AvailList::AvailList(){
	//cantidad = 0;
//}
/*AvailList::AvailList(int referencia){
	this->referencia = referencia;
}
AvailList::AvailList(const AvailList& other){
	referencia = other.referencia;
}
AvailList::~AvailList(){

}*/

/*const int pop()const{
	return lista[cantidad];
}
const int getSize()const{
	return cantidad;
}
void push(int value){
	cantidad++;
	lista[cantidad] = value;
}

const int isEmpty(){
	int m;
	if(cantidad == 0){
		m = -1;
	}
	return m;
}*/
