//Version V2 Gabriel Rodriguez Campos
#include <vector>
#include <iostream>
#include <string>
#include "administrador.h"

using namespace std;

int main(){
    Datos Informacion = AlmacenarDatos();   //Registro los datos
    Administrador Admin("2088226F", "Gabriel"); //Genero un administrador que soy yo.
    vector<Usuario> lista_de_usuarios = Admin.AgregarUsuario(Informacion);  //Agrego los usuarios
    Datos_Turnos lista_de_turnos = GenerarTurnos(Informacion);
    vector<Usuario> Lista_De_usuarios_con_Planificador = Admin.asignarTurnos(lista_de_usuarios, lista_de_turnos, Informacion);
    
    for(int i = 0; i < Lista_De_usuarios_con_Planificador.size(); i++){
        Lista_De_usuarios_con_Planificador[i].Marcar(Informacion);          //Genero las marcas de cada usuario
    
    }
    for(int i = 0; i < Lista_De_usuarios_con_Planificador.size(); i++){
        Lista_De_usuarios_con_Planificador[i].Informe(lista_de_turnos);     //Envio salida de informe de cada usuario

    }
    //Elimino los usuarios
    Admin.EliminarUsuario(Lista_De_usuarios_con_Planificador);
    Admin.EliminarUsuario(lista_de_usuarios);
    for(int i = 0; i < Lista_De_usuarios_con_Planificador.size(); i++){
        Lista_De_usuarios_con_Planificador.pop_back();  
    }
    for(int i = 0; i < lista_de_usuarios.size(); i++){
        lista_de_usuarios.pop_back();                    
    }

    return 0;
}