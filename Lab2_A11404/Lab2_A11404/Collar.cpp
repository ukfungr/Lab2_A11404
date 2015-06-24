#include "stdafx.h"
#include "Collar.h"


Collar::Collar()
{
}


Collar::Collar(string codigo, int valor, int peso)
{
	setCodigo(codigo);
	setValor(valor);
	setPeso(peso);
}


Collar::~Collar()
{
}


void Collar::setCodigo(string c)
{
	codigo = c;
}


void Collar::setValor(int v)
{
	valor = v;
}


void Collar::setPeso(int p)
{
	peso = p;
}


string Collar::getCodigo() const
{
	return codigo;
}


int Collar::getValor() const
{
	return valor;
}


int Collar::getPeso() const
{
	return peso;
}


void Collar::llenarVector(int size, int valMax, int valMin, int pesoMax, int pesoMin)
{
	int c = 1;
	ostringstream s;
	collar = new Collar[size];
	for (int i = 0; i < size; i++){
		s << c;
		string n = s.str();
		codigo = "C-00" + n;
		valor = rand() % (valMax - valMin) + valMin;
		peso = rand() % (pesoMax - pesoMin) + pesoMin;
		c++;
		collar[i] = Collar(codigo, valor, peso);
		s.str(string());//Resetea el ostream para que no acumule los valores anteriores
		s.clear();//Se encarga de limpiar cualquier fallo y problemas con el eof generado por el uso del ostringstream
	}
}


Collar * Collar::getArray()
{
	return collar;
}


void Collar::imprimirVector(int size){

	//unsigned int size = m.size();

	cout << "Collares" << endl;
	cout << setw(10) << "Código" << setw(10) << "Valor" << setw(10) << "Peso" << endl;

	ofstream myFile;
	myFile.open("tesoro.txt", ios_base::app);

	myFile << endl;
	myFile << "Inventario de Collares" << endl;
	myFile << setw(10) << "Código" << setw(10) << "Valor" << setw(10) << "Peso" << endl;

	for (unsigned int i = 0; i < size; i++){
		cout << setw(10) << collar[i].getCodigo();
		cout << setw(10) << collar[i].getValor();
		cout << setw(10) << collar[i].getPeso();
		cout << endl;

		myFile << setw(10) << collar[i].getCodigo();
		myFile << setw(10) << collar[i].getValor();
		myFile << setw(10) << collar[i].getPeso();
		myFile << endl;
	}
	myFile.close();
}