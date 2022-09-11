#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <stdlib.h>
#include "administrador.h"
using namespace std;

Administrador::Administrador(string _Identificador, string _Nombre) : Usuario(_Identificador, _Nombre){
    this->Nombre = _Nombre;
    this->Identificador = _Identificador;
}

Administrador::~Administrador(){
	cout << endl << "Administrador eliminado | Termino del programa";
}

vector<Usuario> Administrador::AgregarUsuario(Datos info){//Agrega todos los usuarios del archivo usuario
	vector<Usuario> Lista_Usuario;
	for(int i = 0; i < info.Usuario.size(); i++){
		int posID = info.Usuario[i].find_first_of(";", 0);
        string identificador = info.Usuario[i].substr(0, posID);
        string Nombre = info.Usuario[i].substr(posID+1, info.Usuario[i].size()); //Lista
        Usuario add_us(identificador, Nombre);
        Lista_Usuario.push_back(add_us);
    }
    return Lista_Usuario;	//Retorna un vector de usuarios
}

void Administrador::EliminarUsuario(vector<Usuario> Lista_De_Usuarios){
	for(int i = 0; i < Lista_De_Usuarios.size(); i++){
		Lista_De_Usuarios.erase(Lista_De_Usuarios.begin()+i);
	}		
}

vector<Usuario> Administrador::asignarTurnos(vector<Usuario> Lista_De_Usuarios, Datos_Turnos datos_de_turno, Datos info){
 	vector<Usuario> vectorU;
 	for(int i = 0; i < Lista_De_Usuarios.size(); i++){//recorre todos los usuario
 		vector<Planificacion> Vector_;
		for(int j = 0; j < info.Planificacion.size(); j++){
			vector<string> VectorPlanificaciones = split(info.Planificacion[j], ';'); 
 			string id = VectorPlanificaciones[5];
 			string id_turno = VectorPlanificaciones[0];
			string dia = VectorPlanificaciones[1];
			string estado = VectorPlanificaciones[2];
			string atraso = VectorPlanificaciones[3];
			string retiro = VectorPlanificaciones[4];
			if(Lista_De_Usuarios[i].Identificador == id){
				for(int s = 0; s < datos_de_turno.Turnos.size(); s++){
					if(datos_de_turno.Turnos[s].Turno_id == stoi(id_turno))
					{
						int turnoa = datos_de_turno.Turnos[s].Turno_id;
						Planificacion add_pl(turnoa, dia, estado, stoi(atraso), stoi(retiro));
						Vector_.push_back(add_pl);
					}
				}
			}
		}
		Lista_De_Usuarios[i].Planificador = Vector_;
		vectorU.push_back(Lista_De_Usuarios[i]);
	}
	return vectorU;
}

