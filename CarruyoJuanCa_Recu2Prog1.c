/******************************************************************************

1)  Diseñar una estructura con 4 campos (uno entero, uno char y una cadena,un float). 
Realizar un constructor por defecto y uno parametrizado solo con tres parámetros. 
Respetar las reglas de estilo vistas en la cátedra .el segundo constructor carga 
el dato float con el entero dividido por 2.
2)Crear una función mostrarDato que recibe un puntero a función( y todo lo que sea necesario) 
y dentro de la función mostrarDato invocar a la función necesaria.
las dos funciones que vamos a pasar por parámetros son estas:

a-hacer la función mostrar cadena que recibe una estructura y muestra su cadena.
b-hacer la función mostrar float que recibe una estructura y muestra su float.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


eEstructura* estructura_new();
eEstructura* estructura_newParametros(char *var1, char *var2, char *var3, char *var4);

int getEntero(eEstructura *this);
char* getCaracter(Employee *this);
char* getCadena(Employee *this);
int getFlotante(Employee *this);

void setEntero(eEstructura *this, int entero);
void setCaracter(eEstructura *this, char *caracter);
void setCadena(eEstructura *this, char *cadena);
void setFlotante(Employee *this, float flotante);

int init(eEstructura *pArray, int limite);
int hardcode(eEstructura *pArray, int limite);
eEstructura* mostrarDato(eEstructura *this, int (*fn)(void*));


int main()
{

typedef struct
{
    int entero;
    char caracter;
    char cadena[20];
    float flotante;
}eEstructura;


    return 0;
}



eEstructura* estructura_new() {
	eEstructura *estruct = malloc(sizeof(eEstructura));
	return estruct;
}

eEstructura* estructura_newParametros(char *var1, char *var2, char *var3, char *var4) {
	int auxEntero;
	int auxFlotante;
	eEstructura *p = estructura_new();
	auxEntero = atoi(var1);
	auxFlotante = atof(var4);
	setEntero(p, auxEntero);
	setCaracter(p, var2);
	setCadena(p, var3);
	setFlotante(p, auxFlotante);
	return p;
}

//GETTERS
int getEntero(eEstructura *this) {
	return this->entero;
}

char* getCaracter(Employee *this) {
	return this->caracter;
}

char* getCadena(Employee *this) {
	return this->cadena;
}

int getFlotante(Employee *this) {
	return this->flotante;
}


//SETTERS
void setEntero(eEstructura *this, int entero) {
	if (entero > 0)
		this->entero = entero;
}

void setCaracter(eEstructura *this, char *caracter) {
	if (caracter[0] != '\0')
		strncpy(this->caracter, caracter, sizeof(this->caracter));
}

void setCadena(eEstructura *this, char *cadena) {
	if (cadena[0] != '\0')
		strncpy(this->cadena, cadena, sizeof(this->cadena));
}

void setFlotante(Employee *this, float flotante) {
	if (flotante > 0)
		this->flotante = flotante;
}

int init(eEstructura *pArray, int limite){

    int ret=-1;
	int auxEntero[limite] = { 0, 0, 0};
	char auxCaracter[][limite] = {"u", "d", "t"};
	char auxCadena[][limite] = { "Uno", "Dos", "Tres"};
	float auxFlotante[limite] = { 0, 0, 0};

	for (int i = 0; i < 4; ++i) {
		pArray[i].entero = auxEntero[i];
		strcpy(pArray[i].caracter, auxCaracter[i]);
		strcpy(pArray[i].cadena, auxCadena[i]);
		pArray[i].flotante = auxFlotante[i];
		ret = 0;
	}
	return ret
}

int hardcode(eEstructura *pArray, int limite){

int ret=-1;
    float auxRes=0;
	int auxEntero[limite] = { 1, 2, 3};
	char auxCaracter[][limite] = {"m", "m", "m"};
	char auxCadena[][limite] = { "German", "Octavio", "Juanca"};
	float auxFlotante[limite] = { 0, 0, 0};

	for (int i = 0; i < 4; ++i) {
		pArray[i].entero = auxEntero[i];
		strcpy(pArray[i].caracter, auxCaracter[i]);
		strcpy(pArray[i].cadena, auxCadena[i]);
		auxRes = auxEntero[i] / 2;
		pArray[i].flotante = auxRes;
		ret = 0;
	}
	return ret
}

eEstructura* mostrarDato(eEstructura *this, int (*fn)(void*)) {
	int check;
	eEstructura *lista = estructura_new();
	void *articulo;
	if (lista != NULL) {
		for (int i = 0; i < ll_len(this); i++) {
			articulo = ll_get(this, i);
			check = fn(articulo);
			if (check) {
				ll_add(lista, articulo);
			}
		}
	}
	return lista;
}
