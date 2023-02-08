#include "Fraccion.h"
#include <iostream>
using namespace std;

Fraccion::Fraccion() {
	num = 0;
	den = 0;
}

Fraccion::Fraccion(int n,int d) {
	num = n;
	den = d;
}

Fraccion::~Fraccion() {}

int Fraccion::getNum() {
	return num;
}

int Fraccion::getDen() {
	return den;
}

void Fraccion::setNum(int n) {
	num = n;
}

void Fraccion::setDen(int d) {
	den = d;
}

Fraccion Fraccion::suma(Fraccion f) {
	int n, d;
	
	if (den == f.getDen()) {
		n = num + f.getNum();
		d = den;
	}
	else {
		d = den * f.getDen();
		n = num * f.getDen() + f.getNum() * den;
	}
	
	Fraccion resp(n,d);
	
	estadSum(true);
	
	return resp.simp();
}

Fraccion Fraccion::resta(Fraccion f) {
	int n, d;
	
	if (den == f.getDen()) {
		n = num - f.getNum();
		d = den;
	}
	else {
		d = den * f.getDen();
		n = num * f.getDen() - f.getNum() * den;
	}
	
	Fraccion resp(n,d);
	
	estadRes(true);
	
	return resp.simp();
}

Fraccion Fraccion::mult(Fraccion f) {
	int n, d;
	d = den * f.getDen();
	n = f.getNum() * num;
	
	Fraccion resp(n,d);
	
	estadMul(true);
	
	return resp.simp();
}

Fraccion Fraccion::divi(Fraccion f) {
	int n, d;
	d = den * f.getNum();
	n = num * f.getDen();
	
	Fraccion resp(n,d);
	
	estadDiv(true);
	
	return resp.simp();
}

Fraccion Fraccion::simp() {
	
	Fraccion copia(num,den);
	
	for (int i = den; i > 0; i--) {
		if ((num%i == 0) and (den%i == 0)) {
			num /= i;
			den /= i;
		}
	}
	
	Fraccion resp(num,den);
	
	if (resp.getDen() != copia.getDen()) {
		estadSimp(true);
	}
	
	return resp;
}

void Fraccion::imprimir() {
	cout << num << "/" << den;
}

int Fraccion::estadSum(bool resp) {
	static int est = 0;
	
	if (resp == true) {
		est++;
		return est;
	}
	else {
		return est;
	}
}

int Fraccion::estadRes(bool resp) {
	static int est = 0;
	
	if (resp == true) {
		est++;
		return est;
	}
	else {
		return est;
	}
}

int Fraccion::estadMul(bool resp) {
	static int est = 0;
	
	if (resp == true) {
		est++;
		return est;
	}
	else {
		return est;
	}
}

int Fraccion::estadDiv(bool resp) {
	static int est = 0;
	
	if (resp == true) {
		est++;
		return est;
	}
	else {
		return est;
	}
}

int Fraccion::estadSimp(bool resp) {
	static int est = 0;
	
	if (resp == true) {
		est++;
		return est;
	}
	else {
		return est;
	}
}
