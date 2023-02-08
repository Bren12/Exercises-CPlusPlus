#ifndef CARRO_H
#define CARRO_H
#include <iostream>
using namespace std;

class Carro{
	// Atributos
	public:
		static int precio, viaje, venta;
	
	public:
		Carro();
		~Carro();
		int calcularKmxPrecio(int km);
		void cotizar();
		void cotizar(int costo);
		void estad();
};

#endif
