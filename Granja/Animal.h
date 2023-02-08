#ifndef ANIMAL_H
#define ANIMAL_H

class Animal {
	// Atributos
	protected:
		int precio, peso;
		
	public:
		static int totalAnimales, totalCrias, dineroAnimales, dineroHuevos, dineroLeche;
	
	// Metodos
	public:
		Animal();
		Animal(int p1, int p2);
		~Animal();
		virtual void imprimir(int pos);
		static void imprimir();
		void generarPeso(bool g);
		virtual void generar(int pos);
		virtual void reproducir(int pos);
		virtual int vender(int pos) = 0;
};

#endif
