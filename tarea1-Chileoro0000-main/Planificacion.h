#ifndef _PLANIFICACION_H_
#define _PLANIFICACION_H_
#include <string>
#include <vector>
#include <iostream>
#include "function.h"

using namespace std;

class Planificacion{
	public:
		int Turno_ID;
		string Dia;
		string Estado;
		int Atraso;
		int Retiro_anticipado;
		Planificacion(int _turno, string _Dia, string _Estado, int _Atraso, int _Retiro_anticipado);
		~Planificacion();
};

#endif