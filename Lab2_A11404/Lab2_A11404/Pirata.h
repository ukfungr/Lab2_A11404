#pragma once

using namespace std;

class Pirata
{
private:
	int capacidad;
	string codigo;
	int valor;
	int peso;

public:
	Pirata();
	Pirata(string, int, int);
	virtual ~Pirata();

	void setCodigo(string);
	void setValor(int);
	void setPeso(int);
	string getCodigo() const;
	int getValor() const;
	int getPeso() const;

	void arregloTemp(Pirata[], int);
	void combinaciones(Pirata[], Pirata[], int, int, int, int);
	bool pesoSum(Pirata[], int);// devuelve verdadero si la combinaci�n es menor o igual a la capacidad del saco
	bool sumaVal(Pirata [], int r);// devuelve verdadero si la suma de las combinaciones son el m�ximo valor
	void imprimir(Pirata [], int);
};

