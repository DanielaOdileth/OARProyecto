#include <string>
#include "AvailList.hpp"

using std::string;


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
