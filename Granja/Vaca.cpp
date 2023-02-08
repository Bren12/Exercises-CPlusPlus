#include "Vaca.h"
#include <iostream>
using namespace std;

Vaca::Vaca() : Animal() {}

Vaca::Vaca(int pre, int pes, int pl) : Animal(pre,pes) {
	precioXleche = pl;
	Animal::generarPeso(false);
}

Vaca::~Vaca() {}

void Vaca::imprimir(int pos) {
	cout << "La vaca ";
	Animal::imprimir(pos);
}

void Vaca::generar(int pos) {
	int l = rand()%4+2;
	
	litros += l;
	cout << "La vaca " << pos+1 << " dio " << l << " litros. Total de litros: " << litros << endl;
	Animal::dineroLeche += precioXleche*l;
}

void Vaca::reproducir(int pos) {
	int c = rand()%10+1;
	
	if (c <= 3) {
		cout << "La vaca ";
		Animal::reproducir(pos);
	}
}

int Vaca::vender(int pos) {
	int c = rand()%10+1;
	
	if (c == 1) {
		int aux = precio*peso;
		Animal::dineroAnimales += aux;
		cout << "La vaca " << pos+1 << " se vendio. La vaca pesaba " << peso 
		     << "kg por lo que se vendio a $" << aux << ". Ganancias Acumuladas: $" 
			 << Animal::dineroAnimales << endl;
		Animal::totalAnimales--;
		return -1;
	}
	return pos;
}

int Vaca::precioXleche = 0;
int Vaca::litros = 0;
