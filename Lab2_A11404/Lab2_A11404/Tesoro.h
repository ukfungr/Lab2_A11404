#pragma once

using namespace std;

class Tesoro
{
private:
	int cont; ///Es el contador para el array que guarda todos los tesoros

public:
	Tesoro();
	void generador(); //Genera el tesoro y lo guarda en un array
	virtual ~Tesoro();
	void destruir(Moneda [], Collar [], Corona [], Anillo [], int, int, int, int);
};

