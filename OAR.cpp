#include <ncurses.h>
#include <cstdlib>
#include <cmath>
#include "Campo.hpp"
#include "Registro.hpp"
#include "Archivo.hpp"
#include "Header.hpp"
#include "AvailList.hpp"
#include "Indice.hpp"
#include "Nodo.hpp"
#include "NodoA.hpp"
#include "NodoPrincipal.hpp"
#include "Arbol.hpp"
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void CrearCampos(vector<Campo>& campos);
Indice ValidarRegistros(vector<Campo>& campos, vector<Registro>& registros, vector<string>& c, Indice nuevo_indice, Arbol nuevo_arbol);
void CrearArchivos(string nombre_archivo, vector<Registro>& registros, vector<string>& c);
void ImprimirArchivo(string nombre_abrir);

int main(int argc, char* argv[]){
	initscr();
	keypad(stdscr, TRUE);
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	bkgd(COLOR_PAIR(1));
	int opcion;
    
    vector<Campo> campos;
    vector<Registro> registros;
    vector<string> c;
    Indice nuevo_indice;
    Arbol nuevo_arbol;
    Header header;
    Archivo nuevo;
   	int cantidad;
   	cantidad = 0;
   	int lista[cantidad];

	printw("***MENU*** \n");
	printw("1. Crear un Archivo \n");
	printw("2. Abrir un Archivo \n");
	printw("3. Salir \n");
	scanw("%d", &opcion);

	if(opcion == 1){
		char nombre_ar[30];
		int opcion2;
		clear();
		refresh();
		char r;
		do{
			addstr("Crear Campos \n");
			CrearCampos(campos);
			printw("Desea crear mas campos? 1.S/2.N \n");
			scanw("%d", &r);
		}while(r != 2);

		clear();
		refresh();
		
		printw("1. Desea ingresar registros \n");
		printw("2. Guardar el Archivo \n");
		printw("3. Mas opciones \n");
		printw("4. Salir \n");

		move(4, 4);
		for(int i = 0; i < campos.size(); i++){
			printw("%s " , campos[i].getNombre().c_str());
		}
		printw(" \n");
		scanw("%d", &opcion2);

		if(opcion2 == 1){
			int rsp;
			do{	
				nuevo_indice = ValidarRegistros(campos, registros, c, nuevo_indice, nuevo_arbol);
				printw("Desea ingresar mas registros 1.S/2.N \n");
				scanw("%d", &rsp);
				if(rsp == 2){
					printw("Ingrese el nombre del Archivo \n");
					getstr(nombre_ar);
					//Guardar el archivo
					CrearArchivos(nombre_ar, registros, c);
					printw("Su archivo fue creado \n");
					scanw("%d", &opcion2);

					header = Header(nombre_ar, campos);
				}
			}while(rsp == 1);
				
		}
		if(opcion2 == 2){
			char nombre_ar[30];
			printf("Ingrese el nombre del Archivo \n");
			getstr(nombre_ar);
			nuevo = Archivo(c, lista, nuevo_arbol, header, nuevo_indice, nombre_ar);

		}
		if(opcion2 == 3){
			clear();
			refresh();

			int respuesta;
			printw("1. Campos \n");
			printw("2. Registro \n");
			printw("3. Salir \n");
			scanw("%d", &respuesta);

			if(respuesta == 1){
				int r;
				printw("1. Modificar \n");
				printw("2. Eliminar \n");
				scanw("%d", &r);

				if(r == 1){
					char nombre_buscar[30];
					printw("Escriba el nombre del campo que desea modificar \n");
					for(int i = 0; i < campos.size(); i++){
						if((campos[i].getNombre()[1] != '*')){
							printw("%s \n ", campos[i].getNombre().c_str());
						}
					}
					getstr(nombre_buscar);

					for(int i = 0; i < campos.size(); i++){
						if(campos[i].getNombre() == nombre_buscar){
							int b;
							printw("Que desa modificar \n");
							printw("1. Nombre \n");
							printw("2. Size \n");
							printw("3. Salir \n");
							scanw("%d", &b);

							if(b == 1){
								printw("Escriba dato \n");
								char n_dato[30];
								getstr(n_dato);

								campos[i].setNombre(n_dato);
							}
							if(b == 2){
								printw("Escriba el dato \n");
								int n_dato;
								scanw("%d",n_dato);

								campos[i].setSize(n_dato);
							}

							if(b == 3){
								exit(EXIT_FAILURE);
							}
						}
					}
				}

			 	clear();
				refresh();
				printw("1. Modificar \n");
				printw("2. Eliminar \n");
				printw("3. Salir \n");
				scanw("%d", &r);

				if(r == 2){
					char nombre_eliminar[30];
					printw("Escriba el nombre del campo que desea eliminar \n");
					for(int i = 0; i < campos.size(); i++){
						if((campos[i].getNombre()[1] != '*')){
							printw("%s \n ", campos[i].getNombre().c_str());
						}
					}
					getstr(nombre_eliminar);

					for(int i = 0; i < campos.size(); i++){
						if(campos[i].getNombre() == nombre_eliminar){
							string m = "*";
							string final;
							final = m+=campos[i].getNombre();
							campos[i].setNombre(final);
						}
					}
				}
				clear();
				refresh();
				printw("1. Modificar \n");
				printw("2. Eliminar \n");
				printw("3. Salir \n");
				scanw("%d", &r);

				if(r == 3){
					exit(EXIT_FAILURE);
				}
			}
			if(respuesta == 2){
				int r;
				printw("1. Modificar \n");
				printw("2. Eliminar \n");
				printw("3. Salir \n");
				scanw("%d", &r);

				if(r == 1){
					//PENDIENTE
					Nodo n;
					int posicion;
					printw("Ingrese la llave a Modificar \n");
					for(int i = 0; i < registros.size(); i++){
						printw(registros[i].toString(c).c_str(), "\n");
					}
					scanw("%d", &posicion);
					n = nuevo_arbol.Buscar(nuevo_arbol, posicion);

					//ValidarRegistros(campos, registros, c, nuevo_indice, nuevo_arbol);

					//n.setLlave();	
				}
				if(r == 2){
					Nodo n; 
					int p;
					int cantidad = 0;
					int lista[cantidad];
					int posicion;
					printw("Ingrese el valor de la llavea eliminar \n");
					for(int i = 0; i< c.size(); i++){
							printw("%s", c[i].c_str(), "\n");
					}
					printw("%d \n", c.size());
					scanw("%d",&posicion);
					n = nuevo_arbol.Buscar(nuevo_arbol, posicion);
					p = -1 * n.getLlave();
					n.setLlave(p);

					lista[cantidad] = posicion;
					cantidad++;

					string m = "*";
					string final;
					final = m+=c[posicion];
					c.push_back(final);

					Nodo temp;
					temp = nuevo_indice.getN();

					while(temp.getLlave() != -1){
						if(temp.getLlave() == posicion){
							temp.setLlave(-2);
							printw("%s", "Su registros fue eliminado");

						}else{
							temp = nuevo_indice.getNext();
						}
					}

					//CUANDO EL USUARIO SALGA DEL PROGRAMA CREEARA EL ARCHIVO
					
				}
			}
			if(respuesta == 3){
				CrearArchivos(nombre_ar, registros, c);
				exit(EXIT_FAILURE);
			}
		}
		if(opcion2 == 4){
			CrearArchivos(nombre_ar, registros, c);
			exit(EXIT_FAILURE);
		}
	}

	if(opcion == 2){
		clear();
		refresh();

		char nombre[30];
		int rsp;
		printw("Ingrese el nombre del archivo a abrir \n");
		getstr(nombre);
		ImprimirArchivo(nombre);

		printw("1. Desea ingresar registros \n");
		printw("2. Mas opciones \n");
		printw("3. Salir \n");
		scanw("%d", &rsp);

		if(rsp == 1){
			do{	
				nuevo_indice = ValidarRegistros(campos, registros, c, nuevo_indice, nuevo_arbol);
				printf("Desea ingresar mas registros 1.S/2.N \n");
				scanw("%d", &rsp);
				if(rsp == 2){
					//Guardar el archivo
					CrearArchivos(nombre, registros, c);

				}
			}while(rsp == 1);
		}

		if(rsp == 2){
			clear();
			refresh();

			int respuesta;
			printw("1. Campos \n");
			printw("2. Registro \n");
			scanw("%d", &respuesta);

			if(respuesta == 1){
				int r;
				printw("1. Modificar \n");
				printw("2. Eliminar \n");
				scanw("%d", &r);

				if(r ==1){
					Nodo n;
					int posicion;
					printw("Ingrese la posicion a Modificar \n");
					for(int i = 0; i < registros.size(); i++){
						printw(registros[i].toString(c).c_str(), "\n");
					}
					scanw("%d", &posicion);
					n = nuevo_arbol.Buscar(nuevo_arbol, posicion);
				}

				if(r == 2){
					Nodo n; 
					int p;
					int cantidad = 0;
					int lista[cantidad];
					int posicion;
					printw("Ingrese el valor de la llavea eliminar \n");
					for(int i = 0; i< c.size(); i++){
						printw("%s", c[i].c_str(), "\n");
					}
					printw("%d \n", c.size());
					scanw("%d",&posicion);
					n = nuevo_arbol.Buscar(nuevo_arbol, posicion);
					p = -1 * n.getLlave();
					n.setLlave(p);

					lista[cantidad] = posicion;
					cantidad++;

					string m = "*";
					string final;
					final = m+=c[posicion];
					c.push_back(final);

					Nodo temp;
					temp = nuevo_indice.getN();

					while(temp.getLlave() != -1){
						if(temp.getLlave() == posicion){
							temp.setLlave(-2);
							printw("%s", "Su registros fue eliminado");

						}else{
							temp = nuevo_indice.getNext();
						}
					}

					//CUANDO EL USUARIO SALGA DEL PROGRAMA CREEARA EL ARCHIVO
				}

			}
			if(respuesta == 2){
				int r;
				printw("1. Modificar \n");
				printw("2. Eliminar \n");
				scanw("%d", &r);

				if(r == 1){
					//PENDIENTE
					Nodo n;
					int posicion;
					printw("Ingrese la llave a Modificar \n");
					for(int i = 0; i < registros.size(); i++){
						printw(registros[i].toString(c).c_str(), "\n");
					}
					scanw("%d", &posicion);
					n = nuevo_arbol.Buscar(nuevo_arbol, posicion);

					//ValidarRegistros(campos, registros, c, nuevo_indice, nuevo_arbol);

					//n.setLlave();
				}
				if(r == 2){
					Nodo n; 
					int p;
					int cantidad = 0;
					int lista[cantidad];
					int posicion;
					printw("Ingrese el valor de la llavea eliminar \n");
					for(int i = 0; i< c.size(); i++){
							printw("%s", c[i].c_str(), "\n");
					}
					printw("%d \n", c.size());
					scanw("%d",&posicion);
					n = nuevo_arbol.Buscar(nuevo_arbol, posicion);
					p = -1 * n.getLlave();
					n.setLlave(p);

					lista[cantidad] = posicion;
					cantidad++;

					string m = "*";
					string final;
					final = m+=c[posicion];
					c.push_back(final);

					Nodo temp;
					temp = nuevo_indice.getN();

					while(temp.getLlave() != -1){
						if(temp.getLlave() == posicion){
							temp.setLlave(-2);
							printw("%s", "Su registros fue eliminado");

						}else{
							temp = nuevo_indice.getNext();
						}
					}

					//CUANDO EL USUARIO SALGA DEL PROGRAMA CREEARA EL ARCHIVO
					
				}
				if(rsp == 3){
				exit(EXIT_FAILURE);
				}
			}
			if(respuesta == 3){
				CrearArchivos(nombre, registros, c);
				exit(EXIT_FAILURE);
			}
		}

	}if (opcion == 3){
		exit(EXIT_FAILURE);
	}

	getch();

	endwin();
	return 0;
}
void CrearCampos(vector<Campo>& campos){
		char nombre_campo[30];
		string tipo_campo;
		int tamano;
		int decimales;
		bool key;

		printw("Nombre del Campo: \n");
		getstr(nombre_campo);
		printw("Tipo del campo: \n");
		int opcion_t;
		printw("1. String \n");
		printw("2. Int \n");
		printw("3. Double \n");
		scanw("%d", &opcion_t);
		if(opcion_t == 1){
			tipo_campo = "String";
		}
		if(opcion_t == 2){
			tipo_campo = "Int";
		}
		if(opcion_t == 3){
			tipo_campo = "Double";
		}
		printw("Tamaño del campo: \n");
		scanw("%d", &tamano);
		if(tipo_campo == "Double"){
			printw("Cantidad de decimales: \n");
			scanw("%d", &decimales);
		}else{
			decimales = 0;
		}
		printw("Desea que este campo sea una llave 1.S/2.N? \n");
		int p;
		scanw("%d", &p);
		if(p == 1){
			if(tipo_campo == "String"){
				printw("Solo se permiten llaves numericas \n");
				key = false;
			}else{
				key = true;
			}
		}else{
			key = false;
		}

	campos.push_back(Campo(nombre_campo, tipo_campo, tamano, decimales, key));
}

Indice ValidarRegistros(vector<Campo>& campos, vector<Registro>& registros, vector<string>& c, Indice nuevo_indice, Arbol nuevo_arbol){
	string lista_datos;
	FILE *archivo_indice;
	lista_datos = "";
	int cantidad = 0;
	int llave;

	for(int i = 0; i < campos.size(); i++){
		if(campos[i].getTipo() == "String"){
			char dato[campos[i].getSize()];
			printw("Ingrese %s \n", campos[i].getNombre().c_str());
			getstr(dato);
			lista_datos+=dato;
			//printw("%d", campos[i].getSize());
			//printw("%c", dato);
			c.push_back(dato);

		}
		if(campos[i].getTipo() == "Double"){
			double dato;
			int m;
			char record[campos[i].getSize()];
			do{
				m = -1;
				printw("Ingrese %s \n", campos[i].getNombre().c_str());
				scanw("%d", dato);
				//getstr(record);
				int m;
				m = pow(10, campos[i].getSize());
				double lim;
				int n;
				int r;
				int total;
				double llave;
				if(campos[i].getSize_dec() != 1){
					n = campos[i].getSize();
					r = campos[i].getSize() - campos[i].getSize_dec();
					total = n-(n-r);
					lim = ( (m-1)*(1/(pow(10, total))));
				}

				/*if(dato < lim){
					printw("Tu dato no es valido para este campo \n");
				}else{*/
					m = 0;
					lista_datos+=record;
					sprintf(record, "%2.f", dato);
					c.push_back(record);
				//}
			}while(m == -1);
		}
		if(campos[i].getTipo() == "Int"){
			int m;
			char record[campos[i].getSize()];

			do{
				int dato;
				m = -1;
				printw("Ingrese %s \n", campos[i].getNombre().c_str());
				scanw("%d", &dato);

				int limite;
				limite = pow(10, campos[i].getSize());

				if(dato >= limite){
					printf("Tu dato no es valido para este campo \n");
				}else{
					m = 0;
					char d[6];
					char r[6];
					sprintf(record, "%d", dato);
					lista_datos+=record;
					c.push_back(record);
					if(campos[i].getKey() == true){
						//AQUI HACE EL INDICE
						Nodo n;
						n = Nodo(c.size(), dato);
						nuevo_indice = Indice(n, Nodo());

						//Haciendo el archivo
						archivo_indice = fopen("Indice.txt", "w");
						sprintf(r, "%d", n.getRRN());
						sprintf(d, "%d", n.getLlave());

						for(int j = 0; j < 6; j++){
							fputc(d[j], archivo_indice);
							fputc(r[j], archivo_indice);	
						}

						fclose(archivo_indice);

						//Arbol
						nuevo_arbol.Agregar(nuevo_arbol, n);
					}
				}
			}while(m == -1);

		}
	}
	Indice indice_nuevo;

	return indice_nuevo;
}

void CrearArchivos(string nombre_archivo, vector<Registro>& registros, vector<string>& c){
	char p;
	char o;
	string m;
	FILE *nuevo_archivo;
	nuevo_archivo = fopen(nombre_archivo.c_str(), "w");

	for(int i = 0; i < c.size(); i++){
		m = c[i].c_str();

		for(int j = 0; j < m.size(); j++){

			p = m[j];

			if(p != '*'){
				fputc(p, nuevo_archivo);
			}else{
				j = m.size();
			}
		}
		fputc('\n',nuevo_archivo);
	}

	fclose(nuevo_archivo);
}

void ImprimirArchivo(string nombre_abrir){
	char caracter;
	FILE *nuevo_archivo;

	nuevo_archivo = fopen(nombre_abrir.c_str(),"r");
	
	if (nuevo_archivo == NULL){

     }else{
        
		printf("\nEl contenido del archivo es\n\n");
	
		 while (feof(nuevo_archivo) == 0){
			caracter = fgetc(nuevo_archivo);
			printf("%c",caracter);
		 }
     }

    fclose(nuevo_archivo);
}