#include "stdafx.h"
#include "Tesoro.h"
#include "Pirata.h"
#include "Moneda.h"
#include "Collar.h"
#include "Corona.h"
#include "Anillo.h"

Tesoro::Tesoro()
{
	cont = 0;
	generador();
}


Tesoro::~Tesoro()
{
}


void Tesoro::generador()
{
	///Monedas
	int cantMax = 10;
	int cantMin = 5;
	int size = rand() % (cantMax - cantMin) + cantMin;

	int valMax = 100;
	int valMin = 1;

	int pesoMax = 200;
	int pesoMin = 100;
	
	Moneda m;
	m.llenarVector(size, valMax, valMin, pesoMax, pesoMin);
	Moneda * n = m.getArray();
	m.imprimirVector(size);
	/*/////////////////////////////////////////////////////////////////////////////*/
	
	///Collares
	int cantMax1 = 5;
	int cantMin1 = 2;
	int size1 = rand() % (cantMax1 - cantMin1) + cantMin1;

	int valMax1 = 4000;
	int valMin1 = 2000;

	int pesoMax1 = 1000;
	int pesoMin1 = 500;

	Collar collar;
	collar.llenarVector(size1, valMax1, valMin1, pesoMax1, pesoMin1);
	Collar * c = collar.getArray();
	collar.imprimirVector(size1);
	/*/////////////////////////////////////////////////////////////////////////////*/
	
	///Coronas
	int cantMax2 = 5;
	int cantMin2 = 1;
	int size2 = rand() % (cantMax2 - cantMin2) + cantMin2;

	int valMax2 = 10000;
	int valMin2 = 1000;

	int pesoMax2 = 2000;
	int pesoMin2 = 500;

	Corona corona;
	corona.llenarVector(size2, valMax2, valMin2, pesoMax2, pesoMin2);
	Corona * cor = corona.getArray();
	corona.imprimirVector(size2);
	/*/////////////////////////////////////////////////////////////////////////////*/

	///Anillos
	int cantMax3 = 7;
	int cantMin3 = 5;
	int size3 = rand() % (cantMax3 - cantMin3) + cantMin3;

	int valMax3 = 200;
	int valMin3 = 100;

	int pesoMax3 = 300;
	int pesoMin3 = 200;

	Anillo anillo;
	anillo.llenarVector(size3, valMax3, valMin3, pesoMax3, pesoMin3);
	Anillo * a = anillo.getArray();
	anillo.imprimirVector(size3);
	
	/////////////////////////////////////////////////////////////////////
	Pirata * pirate;
	int totalSize = size + size1 + size2 + size3;
	pirate = new Pirata[totalSize];
	for (int i = 0; i < size; i++){
		pirate[i] = Pirata(n[i].getCodigo(), n[i].getValor(), n[i].getPeso());
		cont++;
	}

	for (int i = 0; i < size1; i++){
		pirate[cont] = Pirata(c[i].getCodigo(), c[i].getValor(), c[i].getPeso());
		cont++;
	}

	for (int i = 0; i < size2; i++){
		pirate[cont] = Pirata(cor[i].getCodigo(), cor[i].getValor(), cor[i].getPeso());
		cont++;
	}

	for (int i = 0; i < size3; i++){
		pirate[cont] = Pirata(a[i].getCodigo(), a[i].getValor(), a[i].getPeso());
		cont++;
	}
	
	Pirata p;
	p.arregloTemp(pirate, totalSize);
	//destruir(n, c, cor, a, size, size1, size2, size3);
}


/*void Tesoro::destruir(Moneda  n[], Collar c[], Corona cor[], Anillo a[], int size, int size1, int size2, int size3)
{
	for (int i = 0; i < size; i++){
		delete n[i];
	}
	for (int i = 0; i < size1; i++){
		delete c[i];
	}
	for (int i = 0; i < size2; i++){
		delete cor[i];
	}
	for (int i = 0; i < size3; i++){
		delete a[i];
	}
}*/


