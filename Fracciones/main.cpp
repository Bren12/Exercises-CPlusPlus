// Brenda Elena Saucedo González - A00829855
// 22 de mayo de 2021

#include <iostream>
#include <fstream>
#include <time.h> 
#include <stdlib.h>
#include "Fraccion.h"
using namespace std;

void leerArchivo(Fraccion *, Fraccion *, int &);
void simplificar(Fraccion *, Fraccion *, int);
void operaciones(Fraccion *, Fraccion *, int);
void estadistica(Fraccion *, int);

int main() {
	system("color f0");
	srand(time(NULL));
	
	Fraccion f1[100], f2[100];
	int tam = 0, resp, *r, *size;
	
	r = &resp;
	size = &tam;
	
	leerArchivo(f1,f2,*size);
	
	cout << "Operandos:" << endl;
	for (int i = 0; i < tam; i++) {
		f1[i].imprimir();
		cout << "\t";
		f2[i].imprimir();
		cout << endl;
	}
	
	simplificar(f1,f2,tam);
	
	do {
		cout << "\nOperaciones:\n";
		operaciones(f1,f2,tam);
		
		cout << "\nDesea volver a ejecutar el programa con las mismos operandos?\n1 = Si\n2 = No\nRespuesta -> ";
		cin >> *r;
	} while (resp == 1);
	
	estadistica(f1,tam);
	
	return 0;
}

void leerArchivo(Fraccion frac1[], Fraccion frac2[], int &size) {
	ifstream archivo;
	int num1, num2, den1, den2;
	char slash1, slash2;
	
	archivo.open("Operaciones.txt");
	
	if (archivo != NULL) {
		for(int i = 0; archivo >> num1 >> slash1 >> den1 >> num2 >> slash2 >> den2; i++) {
			frac1[i].setNum(num1);
			frac1[i].setDen(den1);
			frac2[i].setNum(num2);
			frac2[i].setDen(den2);
			size++;
		}
	}
	else {
		cout << "Error al abrir el archivo" << endl;
		exit(1);
	}
	
	archivo.close();
}

void simplificar(Fraccion f1[], Fraccion f2[], int tam) {
	cout << "\nOperandos simplificados:" << endl;
	for (int i = 0; i < tam; i++) {
		f1[i].simp();
		f2[i].simp();
		
		f1[i].imprimir();
		cout << "\t";
		f2[i].imprimir();
		cout << endl;
	}
}

void operaciones(Fraccion f1[], Fraccion f2[], int tam) {
	int oper;
	
	for (int i = 0; i < tam; i++) {
		
		oper = rand()%4 + 1;
		
		switch (oper) {
			case 1: {
				f1[i].imprimir();
				cout << " + ";
				f2[i].imprimir();
				cout << " = " ;
				f1[i].suma(f2[i]).imprimir();
				cout << endl;
				break;
			}
			case 2: {
				f1[i].imprimir();
				cout << " - ";
				f2[i].imprimir();
				cout << " = " ;
				f1[i].resta(f2[i]).imprimir();
				cout << endl;
				break;
			}
			case 3: {
				f1[i].imprimir();
				cout << " * ";
				f2[i].imprimir();
				cout << " = " ;
				f1[i].mult(f2[i]).imprimir();
				cout << endl;
				break;
			}
			case 4: {
				f1[i].imprimir();
				cout << " / ";
				f2[i].imprimir();
				cout << " = " ;
				f1[i].divi(f2[i]).imprimir();
				cout << endl;
				break;
			}
		}
	}
}

void estadistica(Fraccion f[], int tam) {
	int s, r, m, d, simp;
	
	s = f[0].estadSum(false);
	r = f[0].estadRes(false);
	m = f[0].estadMul(false);
	d = f[0].estadDiv(false);
	simp = f[0].estadSimp(false);
	
	cout << "\nEl total de sumas realizadas son: " << s << endl;
	cout << "El total de restas realizadas son: " << r << endl;
	cout << "El total de multiplicaciones realizadas son: " << m << endl;
	cout << "El total de divisiones realizadas son: " << d << endl;
	cout << "El total de simplificaciones realizadas son: " << simp << endl;
}
