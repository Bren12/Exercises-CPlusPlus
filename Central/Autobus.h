#ifndef AUTOBUS_H
#define AUTOBUS_H
#include <iostream>
#include <string>
using namespace std;

class Autobus {
	// Atributos
	public:
		string ciudad;
		int hora, precio;
		static int boleto, venta, horaActual;
		
	// Métodos
	public:
		Autobus();
		~Autobus();
		void imprimir();
		void cotizar();
		void cotizar(int cant);
		void estad();
		static void pasoTiempo();
		static int acumTiempo(int h);
};

#endif
