#include "stdafx.h"
#include "Pirata.h"
#include "Tesoro.h"
#include "Moneda.h"
#include "Corona.h"
#include "Anillo.h"
#include "Collar.h"

Pirata::Pirata()
{
	int capacidad = rand() % (2000 - 1000) + 1000;
}


Pirata::Pirata(string codigo, int valor, int peso)
{
	setCodigo(codigo);
	setValor(valor);
	setPeso(peso);
}


Pirata::~Pirata()
{
}


void Pirata::setCodigo(string c)
{
	codigo = c;
}


void Pirata::setValor(int v)
{
	valor = v;
}


void Pirata::setPeso(int p)
{
	peso = p;
}


string Pirata::getCodigo() const
{
	return codigo;
}


int Pirata::getValor() const
{
	return valor;
}


int Pirata::getPeso() const
{
	return peso;
}


void Pirata::arregloTemp(Pirata pirate[], int totalSize)
{
	Pirata * v1;
	v1 = new Pirata[totalSize];
	combinaciones(pirate, v1, 0, totalSize, 0, totalSize);
}


void Pirata::combinaciones(Pirata pirate[], Pirata v1[], int start, int end, int index, int r)
{
	if (pesoSum(v1, r) == true && sumaVal(v1, r) == true){//verifica si el valor de la combinación temporal cumple con la capacidad del saco y si su valor es igual o mayor al de la combinación anterior
		imprimir(v1, index);
	}
	for (int i = start; i <= end && end - i + 1 >= r - index; i++){
		v1[index] = Pirata(pirate[i].getCodigo(), pirate[i].getValor(), pirate[i].getPeso());
		combinaciones(pirate, v1, i + 1, end, index + 1, r);
	}
}


bool Pirata::pesoSum(Pirata v1[], int r)
{
	int pesoMax = 0;
	for (int j = 0; j < r; j++){
		pesoMax = pesoMax + v1[j].getPeso();
	}
	if (pesoMax <= capacidad){
		return true;
	}
}


bool Pirata::sumaVal(Pirata v1[], int r)
{
	int sum = 0;
	for (int j = 0; j < r; j++){
		sum = sum + v1[j].getValor();
	}
	int sumaAnterior = sum;
	if (sum >= sumaAnterior){
		return true;
	}
}


void Pirata::imprimir(Pirata v1[], int index){
	ofstream myfile;
	myfile.open("robado-recursivo.txt");
	myfile << setw(10) << "Código" << setw(10) << "Valor" << setw(10) << "Peso" << endl;
	for (int i = 0; i < index; i++){
		myfile << setw(10) << v1[i].getCodigo();
		myfile << setw(10) << v1[i].getValor();
		myfile << setw(10) << v1[i].getPeso();
		myfile << endl;
	}
	myfile.close();
}