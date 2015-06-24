#pragma once

using namespace std;

class Collar
{
private:
	string codigo;
	int valor;
	int peso;
	Collar * collar;

public:
	Collar();
	Collar(string, int, int);
	virtual ~Collar();

	void setCodigo(string);
	void setValor(int);
	void setPeso(int);
	string getCodigo() const;
	int getValor() const;
	int getPeso() const;

	void llenarVector(int, int, int, int, int);
	void imprimirVector(int);
	Collar * getArray();
};

