#include "Res.h"
#include <iostream>
using namespace std;

Res::Res() : Animal() {}

Res::Res(int pre, int pes) : Animal(pre,pes) {
	Animal::generarPeso(false);
}

Res::~Res() {}

void Res::imprimir(int pos) {
	cout << "La res ";
	Animal::imprimir(pos);
}

void Res::reproducir(int pos) {
	int c = rand()%10+1;
	
	if (c <= 6) {
		cout << "La res ";
		Animal::reproducir(pos);
	}
}

int Res::vender(int pos) {
	int c = rand()%10+1;
	
	if (c <= 4) {
		int aux = precio*peso;
		Animal::dineroAnimales += aux;
		cout << "La res " << pos+1 << " se vendio. La res pesaba " << peso 
		     << "kg por lo que se vendio a $" << aux << ". Ganancias Acumuladas: $" 
			 << Animal::dineroAnimales << endl;
		Animal::totalAnimales--;
		return -1;
	}
	return pos;
}
