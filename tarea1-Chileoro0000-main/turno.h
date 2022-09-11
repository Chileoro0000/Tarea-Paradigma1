#ifndef _TURNO_H_
#define _TURNO_H_
#include <string>
#include <iostream>
using namespace std;

class Turno{
  	public:
  		int Turno_id;
    	string Hora_inicio;
    	string Hora_fin;
    	Turno(int _Turno_id, string _Hora_inicio, string _Hora_fin);
    	~Turno();
    	int TotalHoras();
};

class Turno_Dia : public Turno{
	public:
		int Minutos_atraso_permitidos;
		//int TotalHorasMenosAtraso();
		Turno_Dia(int _Turno_id, string _Hora_inicio, string _Hora_fin, int _Minutos_atraso_permitidos);
		~Turno_Dia();
};

class Turno_Noche : public Turno{
	public:
	int Minutos_retiro_anticipados;
	//int TotalHorasMenosAnticipo();
	Turno_Noche(int _Turno_id, string _Hora_inicio, string _Hora_fin, int _Minutos_retiro_anticipados);
	~Turno_Noche();
};

#endif

