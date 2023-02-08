// Brenda Elena Saucedo González - A00829855
// 29 de mayo de 2021

#include <iostream>
#include <time.h>
#include "Gallina.h"
#include "Vaca.h"
#include "Res.h"
using namespace std;

int main() {
	
	system("color f0");
	srand(time(NULL));
	
	int cant1, cant2, cant3, cantT, pkg, pkv, pkr, phg, plv, dias, pos;
	
	Animal::imprimir();
	
	cout << "Teclee la cantidad de gallinas: ";
	cin >> cant1;
	cout << "Teclee el precio por kilo de gallina: $";
	cin >> pkg;
	cout << "Teclee el precio de cada huevo de gallina: $";
	cin >> phg;
	cout << endl;
	
	cout << "Teclee la cantidad de vacas: ";
	cin >> cant2;
	cout << "Teclee el precio por kilo de vaca: $";
	cin >> pkv;
	cout << "Teclee el precio de la leche de vaca: $";
	cin >> plv;
	cout << endl;
	
	cout << "Teclee la cantidad de reses: ";
	cin >> cant3;
	cout << "Teclee el precio por kilo de res: $";
	cin >> pkr;
	cout << endl;
	
	cantT = cant1+cant2+cant3;
	
	Animal *a[cantT];
	
	for (int i = 0; i < cant1; i++) {
		a[i] = new Gallina(pkg,0,phg);
	}
	
	for (int i = cant1; i < cant2+cant1; i++) {
		a[i] = new Vaca(pkv,0,plv);
	}
	
	for (int i = cant2+cant1; i < cantT; i++) {
		a[i] = new Res(pkr,0);
	}
	
	cout << "------------- Animales en la granja -------------" << endl;
	
	for (int i = 0; i < cantT; i++) {
		a[i]->imprimir(i);
	}
	
	cout << "\nTotal de animales en la granja: " << a[0]->totalAnimales << endl;
	cout << "Total de animales nacidos en la granja: " << a[0]->totalCrias << endl;
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	cout << "\nCuantos dias se va a observar la granja? ";
	cin >> dias;
	
	int eliminados[cantT];
	
	for (int i = 0; i < cantT; i++) {
		eliminados[i] = i;
	}
	
	for (int j = 0; j < dias; j++) {
		cout << "\n---------------- Dia " << j+1 << " ----------------" << endl;
		for (int i = 0; i < cantT; i++) {
			if (eliminados[i] == i) {
				a[i]->generar(i);
				a[i]->reproducir(i);
				eliminados[i] = a[i]->vender(i);
			}
		}
		system("PAUSE()");
	}
	
	cout << "\nTotal de animales restantes en la granja: " << a[0]->totalAnimales << endl;
	cout << "Total de crias que nacieron en los dias que se observo la granja: " << a[0]->totalCrias << endl;
	cout << "Ganancias acumuladas por la venta de huevos: $" << a[0]->dineroHuevos << endl;
	cout << "Ganancias acumuladas por la venta de litros de leche: $" << a[0]->dineroLeche << endl;
	cout << "Ganancias acumuladas por la venta de animales: $" << a[0]->dineroAnimales << endl;
	
	return 0;
}
