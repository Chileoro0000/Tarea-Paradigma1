#ifndef _ADMINISTRADOR_H_
#define _ADMINISTRADOR_H_
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "usuario.h"

using namespace std;

class Administrador: public Usuario{
	public:
		Administrador(string _Identificador, string _Nombre);
		~Administrador();
		vector<Usuario> asignarTurnos(vector<Usuario> Lista_De_Usuarios, Datos_Turnos datos_de_turno, Datos info); //proceso
		vector<Usuario> AgregarUsuario(Datos info); //lista
		void EliminarUsuario(vector<Usuario> Lista_De_Usuarios); //proceso
};

#endif