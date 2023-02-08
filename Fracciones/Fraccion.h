#ifndef FRACCION_H
#define FRACCION_H

class Fraccion {
	
	// Atributos
	private:
		int num, den;
		
	// Métodos
	public:
		// Constructor Default
		Fraccion();
		// Constructos con 2 Parámetros
		Fraccion(int n,int d);
		// Destructor Default
		~Fraccion();
		// Métodos de Acceso
		int getNum();
		int getDen();
		// Métodos de Modificación
		void setNum(int n);
		void setDen(int d);
		// Método para sumar fracciones
		Fraccion suma(Fraccion f);
		// Método para restar fracciones
		Fraccion resta(Fraccion f);
		// Método para multiplicar fracciones
		Fraccion mult(Fraccion f);
		// Método para dividir fracciones
		Fraccion divi(Fraccion f);
		// Método para simplificar
		Fraccion simp();
		// Método para imprimir una fracción
		void imprimir();
		// Método para estadística
		static int estadSum(bool resp);
		static int estadRes(bool resp);
		static int estadMul(bool resp);
		static int estadDiv(bool resp);
		static int estadSimp(bool resp);
};

#endif
