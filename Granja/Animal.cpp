#include "Animal.h"
#include "Gallina.h"
#include "Vaca.h"
#include <iostream>
using namespace std;

Animal::Animal() {
	precio = 0;
	peso = 0;
}

Animal::Animal(int p1, int p2) {
	precio = p1;
	peso = p2;
}

Animal::~Animal() {}

void Animal::imprimir(int pos) {
	cout << pos+1 << " tiene un precio total de $" << precio*peso << " y un peso de " << peso << endl;
}

void Animal::imprimir() {
	cout << "------------- Bienvenidos a la granja! -------------" << endl << endl;
}

void Animal::generarPeso(bool g) {
	if (g == true) {
		peso = rand()%3 + 1;
	}
	else {
		peso = rand()%130 + 51;
	}
	
	totalAnimales += 1;
}

void Animal::generar(int pos) {}

void Animal::reproducir(int pos) {
	totalCrias++;
	cout << pos+1 << " tuvo una cria. Total de crias: " << totalCrias << endl;
}

int Animal::totalAnimales = 0;
int Animal::totalCrias = 0;
int Animal::dineroAnimales = 0;
int Animal::dineroHuevos = 0;
int Animal::dineroLeche = 0;
