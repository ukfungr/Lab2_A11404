#include "stdafx.h"
#include "Anillo.h"


Anillo::Anillo()
{
}


Anillo::Anillo(string codigo, int valor, int peso)
{
	setCodigo(codigo);
	setValor(valor);
	setPeso(peso);
}


Anillo::~Anillo()
{
}


void Anillo::setCodigo(string c)
{
	codigo = c;
}


void Anillo::setValor(int v)
{
	valor = v;
}


void Anillo::setPeso(int p)
{
	peso = p;
}


string Anillo::getCodigo() const
{
	return codigo;
}


int Anillo::getValor() const
{
	return valor;
}


int Anillo::getPeso() const
{
	return peso;
}


void Anillo::llenarVector(int size, int valMax, int valMin, int pesoMax, int pesoMin)
{
	int c = 1;
	ostringstream s;
	anillo = new Anillo[size];
	for (int i = 0; i < size; i++){
		s << c;
		string n = s.str();
		codigo = "A-00" + n;
		valor = rand() % (valMax - valMin) + valMin;
		peso = rand() % (pesoMax - pesoMin) + pesoMin;
		c++;
		anillo[i] = Anillo(codigo, valor, peso);
		s.str(string());//Resetea el ostream para que no acumule los valores anteriores
		s.clear();//Se encarga de limpiar cualquier fallo y problemas con el eof generado por el uso del ostringstream
	}
}


Anillo * Anillo::getArray()
{
	return anillo;
}


void Anillo::imprimirVector(int size)
{

	//unsigned int size = m.size();

	cout << "Anillos" << endl;
	cout << setw(10) << "Código" << setw(10) << "Valor" << setw(10) << "Peso" << endl;

	ofstream myFile;
	myFile.open("tesoro.txt", ios_base::app);

	myFile << endl;
	myFile << "Inventario de Anillos" << endl;
	myFile << setw(10) << "Código" << setw(10) << "Valor" << setw(10) << "Peso" << endl;

	for (unsigned int i = 0; i < size; i++){
		cout << setw(10) << anillo[i].getCodigo();
		cout << setw(10) << anillo[i].getValor();
		cout << setw(10) << anillo[i].getPeso();
		cout << endl;

		myFile << setw(10) << anillo[i].getCodigo();
		myFile << setw(10) << anillo[i].getValor();
		myFile << setw(10) << anillo[i].getPeso();
		myFile << endl;
	}
	myFile.close();
}
