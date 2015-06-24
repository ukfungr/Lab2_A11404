#pragma once

using namespace std;

class Moneda
{
private:
	string codigo;
	int valor;
	int peso;
	Moneda * m;

public:
	Moneda();
	Moneda(string, int, int);
	virtual ~Moneda();

	void setCodigo(string);
	void setValor(int);
	void setPeso(int);
	string getCodigo() const;
	int getValor() const;
	int getPeso() const;

	void llenarVector(int, int, int, int, int);
	void imprimirVector(int);
	Moneda * getArray();
};

