#include "Carro.h"

Carro::Carro() {}

Carro::~Carro() {}

int Carro::calcularKmxPrecio(int km) {
	return precio*km;
}

void Carro::cotizar() {
	viaje++;
}

void Carro::cotizar(int costo) {
	venta += costo;
}

void Carro::estad() {
	cout << "Carro particular -> Total de viajes: " << viaje << endl;
	cout << "Carro particular -> Venta total: $" << venta << endl;
}

int Carro::precio = 0;
int Carro::viaje = 0;
int Carro::venta = 0;
