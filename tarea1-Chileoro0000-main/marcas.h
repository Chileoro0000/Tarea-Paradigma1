#ifndef _MARCAS_H_
#define _MARCAS_H_
#include <string>
#include <vector>
using namespace std;

class Marca{
	public:
		string Dia;
		string Hora;
		int Tipo;
		Marca(string _Dia, string _Hora,  int _Tipo);
		~Marca();
};

#endif