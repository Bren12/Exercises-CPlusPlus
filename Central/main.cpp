// Brenda Elena Saucedo González - A00829855
// 24 de mayo de 2021

#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <cstring>
#include "Autobus.h"
#include "Carro.h"
using namespace std;

void leerArchivo(Autobus *, int &);
void menu(int, Autobus *, Carro, int, int);
int buscar(Autobus *, string, int, int);
void estadistica(Autobus *, Carro);

int main() {
	system("color f0");
	srand(time(NULL));
	
	Autobus ado[50];
	Carro uber;
	int pKm, tam, resp;
	
	leerArchivo(ado,tam);
	
	cout << "Precio por Km del viaje en carro: ";
	cin >> pKm;
	uber.precio = pKm;
	
	do {
		cout << "\nMenu\t\t\t\t\tHora: " << ado[0].horaActual << "\n1 = Viajar en autobus\n2 = Viajar en carro particular\n3 = Salir\nOpcion: ";
		cin >> resp;
		
		menu(resp,ado,uber,tam,ado[0].horaActual);
		
		if (resp == 1 | resp == 2) {
			ado[0].pasoTiempo();
		}
		
	} while(resp != 3);
	
	ado[0].estad();
	uber.estad();
	cout << "Total de horas que se trabajo: " << ado[1].acumTiempo(0) << endl;
	
	return 0;
}

void leerArchivo(Autobus ado[], int &size) {
	ifstream archivo;
	char ciudad[20];
	int hora, precio;
	
	archivo.open("Corridas.txt");
	
	if (archivo != NULL) {
		cout << "-------------------CORIRRIDAS-------------------" << endl; 
		for(int i = 0; archivo >> ciudad >> hora >> precio; i++) {
			strupr(ciudad);
			string strCiudad(ciudad);
			ado[i].ciudad = ciudad;
			ado[i].hora = hora;
			ado[i].precio = precio;
			
			ado[i].imprimir();
			size++;
		}
		cout << endl;
	}
	else {
		cout << "Error al abrir el archivo" << endl;
		exit(1);
	}
	
	archivo.close();
}

void menu(int resp, Autobus ado[], Carro uber, int tam, int hrRan) {
	char ciudad[20];
	int hora, opcHr, pos = -1, opcCom, aux, aux2 = 0, km;
	
	switch (resp) {
		case 1: {
			cout << "\nDestino: ";
			cin >> ciudad;
			strupr(ciudad);
			string strCiudad(ciudad);
			do {
				cout << "\n1 = Teclear una hora deseada\n2 = Proxima corrida\nOpcion: ";
				cin >> opcHr;
				if (opcHr == 1) {
					cout << "\nHora deseada: ";
					cin >> hora;
					pos = buscar(ado,strCiudad,hora,tam);
					if (pos != -1) {
						cout << "\nBoleto: " << endl;
						ado[pos].imprimir();
						do {
							cout << "\n1 = Comprar el boleto de viaje\t\t2 = Cancelar\nOpcion: ";
							cin >> opcCom;
						} while (opcCom != 1 & opcCom != 2);
						
						if (opcCom == 1) {
							ado[pos].cotizar(1);
							ado[pos].cotizar();
							cout << "\nCompra exitosa!" << endl;
						}
					}
					else {
						cout << "\nNo existe ese viaje" << endl;
					}
				}
				else { 
					if (opcHr == 2) {
						for (int hr = hrRan+1; hr < hrRan+23; hr++) {
							aux = buscar(ado,strCiudad,hr,tam);
							if (aux != -1 & aux2 == 0) {
								pos = aux;
								aux2++;
							}
						}
						if (pos != -1) {
							cout << "\nBoleto: " << endl;
							ado[pos].imprimir();
							do {
								cout << "\n1 = Comprar el boleto de viaje\n2 = Cancelar\nOpcion: ";
								cin >> opcCom;
							} while (opcCom != 1 & opcCom != 2);
							
							if (opcCom == 1) {
								ado[pos].cotizar(1);
								ado[pos].cotizar();
								cout << "\nCompra exitosa!" << endl;
							}
						}
						else {
							cout << "\nNo existe ese viaje" << endl;
						}
					}
				}
			} while (opcHr != 1 & opcHr != 2);
			
			break;
		}
		case 2: {
			cout << "\nDistancia del viaje en km: ";
			cin >> km;
			int p = uber.calcularKmxPrecio(km);
			cout << "\nEl viaje en carro particular cuesta $" << p << endl;
			
			do {
				cout << "\n1 = Comprar el boleto de viaje\n2 = Cancelar\nOpcion: ";
				cin >> opcCom;
			} while (opcCom != 1 & opcCom != 2);
			
			if (opcCom == 1) {
				uber.cotizar();
				uber.cotizar(p);
				cout << "\nCompra exitosa!" << endl;
			}
			break;
		}
	}
	
}

int buscar(Autobus ado[], string ciudad, int hr, int tam) {
	
	if (hr >= 24) {
		hr -= 24;
	}
	
	for (int i = 0; i < tam; i++) {
		if (ado[i].ciudad == ciudad & ado[i].hora == hr) {
			return i;
		}
	}
	return -1;
}
