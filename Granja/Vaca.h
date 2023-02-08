#ifndef VACA_H
#define VACA_H

#include "Animal.h"

class Vaca : public Animal {
	// Atributos
	public:
		static int precioXleche, litros;
		
	// Meotodos
	public:
		Vaca();
		Vaca(int pre, int pes, int pl);
		~Vaca();
		void imprimir(int pos);
		void generar(int pos);
		void reproducir(int pos);
		int vender(int pos);
};

#endif
