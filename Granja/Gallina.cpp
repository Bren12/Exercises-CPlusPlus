#include "Gallina.h"
#include <iostream>
using namespace std;

Gallina::Gallina() : Animal() {}

Gallina::Gallina(int pre, int pes, int ph) : Animal(pre,pes) {
	precioXhuevo = ph;
	Animal::generarPeso(true);
}

Gallina::~Gallina() {}

void Gallina::imprimir(int pos) {
	cout << "La gallina ";
	Animal::imprimir(pos);
}

void Gallina::generar(int pos) {
	int h = rand()%10+1;
	
	if (h <= 9) {
		huevos++;
		cout << "La gallina " << pos+1 << " puso un huevo. Total de huevos: " << huevos << endl;
		Animal::dineroHuevos += precioXhuevo;
	}
}

void Gallina::reproducir(int pos) {
	int c = rand()%10+1;
	
	if (c <= 4) {
		cout << "La gallina ";
		Animal::reproducir(pos);
	}
}

int Gallina::vender(int pos) {
	int c = rand()%10+1;
	
	if (c <= 2) {
		int aux = precio*peso;
		Animal::dineroAnimales += aux;
		cout << "La gallina " << pos+1 << " se vendio. La gallina pesaba " << peso 
		     << "kg por lo que se vendio a $" << aux << ". Ganancias Acumuladas: $" 
			 << Animal::dineroAnimales << endl;
		Animal::totalAnimales--;
		return -1;
	}
	return pos;
}

int Gallina::precioXhuevo = 0;
int Gallina::huevos = 0;
