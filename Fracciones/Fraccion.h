#ifndef FRACCION_H
#define FRACCION_H

class Fraccion {
	
	// Atributos
	private:
		int num, den;
		
	// M�todos
	public:
		// Constructor Default
		Fraccion();
		// Constructos con 2 Par�metros
		Fraccion(int n,int d);
		// Destructor Default
		~Fraccion();
		// M�todos de Acceso
		int getNum();
		int getDen();
		// M�todos de Modificaci�n
		void setNum(int n);
		void setDen(int d);
		// M�todo para sumar fracciones
		Fraccion suma(Fraccion f);
		// M�todo para restar fracciones
		Fraccion resta(Fraccion f);
		// M�todo para multiplicar fracciones
		Fraccion mult(Fraccion f);
		// M�todo para dividir fracciones
		Fraccion divi(Fraccion f);
		// M�todo para simplificar
		Fraccion simp();
		// M�todo para imprimir una fracci�n
		void imprimir();
		// M�todo para estad�stica
		static int estadSum(bool resp);
		static int estadRes(bool resp);
		static int estadMul(bool resp);
		static int estadDiv(bool resp);
		static int estadSimp(bool resp);
};

#endif
