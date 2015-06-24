#include "stdafx.h"
#include "Moneda.h"


Moneda::Moneda()
{
}


Moneda::Moneda(string codigo, int valor, int peso) 
{
	setCodigo(codigo);
	setValor(valor);
	setPeso(peso);
}


Moneda::~Moneda() 
{
}

void Moneda::setCodigo(string c)
{
	codigo = c;
}


void Moneda::setValor(int v)
{
	valor = v;
}


void Moneda::setPeso(int p)
{
	peso = p;
}


string Moneda::getCodigo() const
{
	return codigo;
}


int Moneda::getValor() const
{
	return valor;
}


int Moneda::getPeso() const
{
	return peso;
}


void Moneda::llenarVector(int size, int valMax, int valMin, int pesoMax, int pesoMin)
{
	int c = 1;
	ostringstream s;
	m = new Moneda [size];
	for (int i = 0; i < size; i++){
		s << c;
		string n = s.str();
		codigo = "M-00" + n;
		valor = rand() % (valMax - valMin) + valMin;
		peso = rand() % (pesoMax - pesoMin) + pesoMin;
		c++;
		m[i] = Moneda(codigo, valor, peso);
		s.str(string());//Resetea el ostream para que no acumule los valores anteriores
		s.clear();//Se encarga de limpiar cualquier fallo y problemas con el eof generado por el uso del ostringstream
	}
}


Moneda * Moneda::getArray() 
{
	return m;
}


void Moneda::imprimirVector(int size){

	//unsigned int size = m.size();

	cout << "Monedas" << endl;
	cout << setw(10) << "Código" << setw(10) << "Valor" << setw(10) << "Peso" << endl;

	ofstream myFile;
	myFile.open("tesoro.txt");

	myFile << endl;
	myFile << "Inventario de Monedas" << endl;
	myFile << setw(10) << "Código" << setw(10) << "Valor" << setw(10) << "Peso" << endl;

	for (unsigned int i = 0; i < size; i++){
		cout << setw(10) << m[i].getCodigo();
		cout << setw(10) << m[i].getValor();
		cout << setw(10) << m[i].getPeso();
		cout << endl;

		myFile << setw(10) << m[i].getCodigo();
		myFile << setw(10) << m[i].getValor();
		myFile << setw(10) << m[i].getPeso();
		myFile << endl;
	}
	myFile.close();
}