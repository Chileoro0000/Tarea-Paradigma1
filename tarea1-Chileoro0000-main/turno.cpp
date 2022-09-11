#include <string>
#include <iostream>
#include "turno.h"
using namespace std;

Turno::Turno(int _Turno_id, string _Hora_inicio, string _Hora_fin){
	this->Turno_id = _Turno_id;
	this->Hora_inicio = _Hora_inicio;
	this->Hora_fin = _Hora_fin;
}

Turno::~Turno(){
	//cout << endl << "Turno eliminado";
}



int Turno::TotalHoras(){
	int horainicio = stoi(Hora_inicio);
	int horafin = stoi(Hora_fin);
	if(horafin-horainicio > 6){
		cout << "El turno: " << Turno_id << " se pasa de las horas permitidas (6 HRS)." << endl;
	}
	if(horainicio < 6){
		cout << "El turno: " << Turno_id << " no cumple con el horario." << endl;
	}
	if(horafin > 22){
		cout << "El turno: " << Turno_id << " no cumple con el horario." << endl;
	}
	return horafin-horainicio;
}



Turno_Dia::Turno_Dia(int _Turno_id, string _Hora_inicio, string _Hora_fin, int _Minutos_atraso_permitidos): Turno(_Turno_id, _Hora_inicio, _Hora_fin)
{
	this->Minutos_atraso_permitidos = _Minutos_atraso_permitidos;
}

Turno_Dia::~Turno_Dia(){
	//cout << endl << "Turno dia eliminado";
}




Turno_Noche::Turno_Noche(int _Turno_id, string _Hora_inicio, string _Hora_fin, int _Minutos_retiro_anticipados): Turno(_Turno_id, _Hora_inicio, _Hora_fin){
	this->Minutos_retiro_anticipados = _Minutos_retiro_anticipados;
}

Turno_Noche::~Turno_Noche(){
	//cout << endl << "Turno noche eliminado";
}
