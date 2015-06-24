#pragma once

using namespace std;

class Corona
{
private:
	string codigo;
	int valor;
	int peso;
	Corona * corona;

public:
	Corona();
	Corona(string, int, int);
	~Corona();

	void setCodigo(string);
	void setValor(int);
	void setPeso(int);
	string getCodigo() const;
	int getValor() const;
	int getPeso() const;

	void llenarVector(int, int, int, int, int);
	void imprimirVector(int);
	Corona * getArray();
};

