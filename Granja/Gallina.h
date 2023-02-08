#ifndef GALLINA_H
#define GALLINA_H

#include "Animal.h"

class Gallina : public Animal {
	// Atributos
	public:
		static int precioXhuevo, huevos;
		
	// Metodos
	public:
		Gallina();
		Gallina(int pre, int pes, int ph);
		~Gallina();
		void imprimir(int pos);
		void generar(int pos);
		void reproducir(int pos);
		int vender(int pos);
};

#endif
