#pragma once

using namespace std;

class Anillo
{
private:
	string codigo;
	int valor;
	int peso;
	Anillo * anillo;

public:
	Anillo();
	Anillo(string, int, int);
	virtual ~Anillo();

	void setCodigo(string);
	void setValor(int);
	void setPeso(int);
	string getCodigo() const;
	int getValor() const;
	int getPeso() const;

	void llenarVector(int, int, int, int, int);
	void imprimirVector(int);
	Anillo * getArray();
};

