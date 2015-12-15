#include <string>
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include "Arbol.hpp"

using namespace std;

Arbol::Arbol(){

}
Arbol::Arbol(NodoPrincipal padre, NodoA hijos){
	this->padre = padre;
	this->hijos = hijos;
}
Arbol::Arbol(const Arbol& other){
	padre = other.padre;
}
Arbol::~Arbol(){

}	
NodoPrincipal Arbol::getPadre(){
	return padre;
}
NodoA Arbol::getHijos(){
	return hijos;
}

void Arbol::setPadre(NodoPrincipal nuevo){
	this->padre = nuevo;
}

void Arbol::setHijos(NodoA nhijos){
	this->hijos = nhijos;
}

void Arbol::Agregar(Arbol arbol, Nodo nuevo){
	Nodo temp;
	int cantidad;
	cantidad = 0;
	while(cantidad < 6){
		if(cantidad == 0){
			temp = arbol.getPadre().getNodos(cantidad+1);
			arbol.getPadre().setNodo(cantidad+1, nuevo);
			cantidad++;
		}else{
			if(arbol.getPadre().getNodos(cantidad-1).getLlave() > nuevo.getLlave()){
				int p;
				Nodo llave;
				p = cantidad;

				llave = arbol.getPadre().getNodos(cantidad-1);
				arbol.getPadre().setNodo(cantidad+1, llave) ;
				arbol.getPadre().setNodo(cantidad-1, nuevo);
				temp = arbol.getPadre().getNodos(cantidad);

				while(p > 1){
					if(arbol.getPadre().getNodos(p).getLlave() > arbol.getPadre().getNodos(p-1).getLlave()){
						Nodo o;
						o = arbol.getPadre().getNodos(p-1);
						arbol.getPadre().setNodo(p-1, arbol.getPadre().getNodos(p));
					}else{
						p = 1;
					}
				}
				cantidad++;
			}else{
				arbol.getPadre().setNodo(cantidad + 1, nuevo);
				temp = arbol.getPadre().getNodos(cantidad+1);
				cantidad++;
			}
		}
	}

	if(cantidad == 6){
		NodoPrincipal nueva, nder, nizq;
		nueva.setNodo(1, arbol.getPadre().getNodos(3));
		//arbol.setPadre(nueva);

		nder.setNodo(1, arbol.getPadre().getNodos(1));
		nder.setNodo(2, arbol.getPadre().getNodos(2));
		arbol.getHijos().setHijo_der(nder);

		nizq.setNodo(1, arbol.getPadre().getNodos(4));
		nizq.setNodo(2, arbol.getPadre().getNodos(5));
		nizq.setNodo(3, arbol.getPadre().getNodos(6));

		arbol.setPadre(nueva);

		cantidad = 0;
	}
}
Nodo Arbol::Buscar(Arbol arbol, int buscar,int cantidad){
	int b;
	b =0;

	while(cantidad < 6){
		while(arbol.getPadre().getNodos(cantidad + 1).getLlave() != -1){
			if(arbol.getPadre().getNodos(cantidad + 1).getLlave() == buscar){
				b = 2;
				return arbol.getPadre().getNodos(cantidad + 1);
			}else{
				cantidad++;
			}
		}
		while(arbol.getHijos().getHijo_der().getNodos(cantidad+1).getLlave() != -1){
			if(arbol.getHijos().getHijo_der().getNodos(cantidad+1).getLlave() == buscar){
				b = 2;
				return arbol.getHijos().getHijo_der().getNodos(cantidad+1);
			}else{
				cantidad++;
			}
		}
		while(arbol.getHijos().getHijo_izq().getNodos(cantidad+1).getLlave() != -1){
			if(arbol.getHijos().getHijo_izq().getNodos(cantidad+1).getLlave() == buscar){
				b = 2;
				return arbol.getHijos().getHijo_izq().getNodos(cantidad+1);
			}else{
				cantidad++;
			}
		}
	}

	printf("%s\n", "Su registro no fue encontrado");
}