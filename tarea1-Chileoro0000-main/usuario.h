#ifndef _USUARIO_H_
#define _USUARIO_H_
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Planificacion.h"
#include "marcas.h"

using namespace std;

class Usuario{
	public:
        vector<Marca> Marcas;
        vector<Planificacion> Planificador;
		string Identificador;
        string Nombre;
		Usuario(string _Identificador, string _Nombre);
		~Usuario();
		void Marcar(Datos info);
		void Informe(Datos_Turnos lista_de_turnos);
};


#endif 