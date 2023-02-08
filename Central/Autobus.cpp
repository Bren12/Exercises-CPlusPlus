#include "Autobus.h"

Autobus::Autobus() {
	ciudad = "NA";
	hora = 0;
	precio = 0;
//	horaActual = 0;
}

Autobus::~Autobus() {}

void Autobus::imprimir() {
	cout << ciudad << " a las " << hora << " hrs con un precio de $" << precio << endl;
}

void Autobus::cotizar(int cant) {
	boleto += cant;
}

void Autobus::cotizar() {
	venta += precio;
}

void Autobus::estad() {
	cout << "\nAutobuses -> Total de boletos: " << boleto << endl;
	cout << "Autobuses -> Venta total: $" << venta << endl;
}

void Autobus::pasoTiempo() {
	int random = rand()%4;
	
	acumTiempo(random);
	
	horaActual += random;
	
	if (horaActual >= 24) {
		horaActual -= 24;
	}
}

int Autobus::acumTiempo(int h) {
	static int acum = 0;
	acum += h;
	return acum;
}

int Autobus::boleto = 0;
int Autobus::venta = 0;
int Autobus::horaActual = 0;
