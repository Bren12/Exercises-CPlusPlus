#ifndef RES_H
#define RES_H

#include "Animal.h"

class Res : public Animal {
	// Atributos
	public:
		static int precioXkilo;
		
	public:
		Res();
		Res(int pre, int pes);
		~Res();
		void imprimir(int pos);
		void reproducir(int pos);
		int vender(int pos);
};

#endif
