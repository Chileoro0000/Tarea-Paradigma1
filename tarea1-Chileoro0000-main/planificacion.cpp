#include <string>
#include <vector>
#include <iostream>
#include "Planificacion.h"

using namespace std;

Planificacion::Planificacion(int _Turno_ID ,string _Dia, string _Estado, int _Atraso, int _Retiro_anticipado){
	this->Turno_ID = _Turno_ID;
	this->Dia = _Dia;
	this->Estado = _Estado;
	this->Atraso = _Atraso;
	this->Retiro_anticipado = _Retiro_anticipado;
}

Planificacion::~Planificacion(){
	//cout << "Planificacion destruida";
}
