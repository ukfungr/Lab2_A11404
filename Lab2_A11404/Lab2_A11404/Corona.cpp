#include "stdafx.h"
#include "Corona.h"


Corona::Corona()
{
}


Corona::Corona(string codigo, int valor, int peso)
{
	setCodigo(codigo);
	setValor(valor);
	setPeso(peso);
}


Corona::~Corona()
{
}


void Corona::setCodigo(string c)
{
	codigo = c;
}


void Corona::setValor(int v)
{
	valor = v;
}


void Corona::setPeso(int p)
{
	peso = p;
}


string Corona::getCodigo() const
{
	return codigo;
}


int Corona::getValor() const
{
	return valor;
}


int Corona::getPeso() const
{
	return peso;
}


void Corona::llenarVector(int size, int valMax, int valMin, int pesoMax, int pesoMin)
{
	int c = 1;
	ostringstream s;
	corona = new Corona[size];
	for (int i = 0; i < size; i++){
		s << c;
		string n = s.str();
		codigo = "Cn-00" + n;
		valor = rand() % (valMax - valMin) + valMin;
		peso = rand() % (pesoMax - pesoMin) + pesoMin;
		c++;
		corona[i] = Corona(codigo, valor, peso);
		s.str(string());//Resetea el ostream para que no acumule los valores anteriores
		s.clear();//Se encarga de limpiar cualquier fallo y problemas con el eof generado por el uso del ostringstream
	}
}


Corona * Corona::getArray()
{
	return corona;
}


void Corona::imprimirVector(int size){

	//unsigned int size = m.size();

	cout << "Coronas" << endl;
	cout << setw(10) << "Código" << setw(10) << "Valor" << setw(10) << "Peso" << endl;

	ofstream myFile;
	myFile.open("tesoro.txt", ios_base::app);

	myFile << endl;
	myFile << "Inventario de Coronas" << endl;
	myFile << setw(10) << "Código" << setw(10) << "Valor" << setw(10) << "Peso" << endl;

	for (unsigned int i = 0; i < size; i++){
		cout << setw(10) << corona[i].getCodigo();
		cout << setw(10) << corona[i].getValor();
		cout << setw(10) << corona[i].getPeso();
		cout << endl;

		myFile << setw(10) << corona[i].getCodigo();
		myFile << setw(10) << corona[i].getValor();
		myFile << setw(10) << corona[i].getPeso();
		myFile << endl;
	}
	myFile.close();
}
