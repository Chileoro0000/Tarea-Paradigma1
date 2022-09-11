#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
#include "usuario.h"

Usuario::Usuario(string _Identificador, string _Nombre){
    this->Nombre = _Nombre;
    this->Identificador = _Identificador;
}

Usuario::~Usuario(){
    //cout << endl <<"Usuario eliminado"<< endl;
}

void Usuario::Marcar(Datos info){
    for(int j = 0; j < info.Marcas.size(); j++){ 
        //CONDICION PARA VERIFICAR SI ES EL RUT Y LA MARCA PERTENECE
        vector<string> VectorMarcas = split(info.Marcas[j], ';');
        string subcadenaNom = VectorMarcas[0];
        if(Identificador == subcadenaNom){
            string dia = VectorMarcas[1];
            string hora = VectorMarcas[2];
            string tipo = VectorMarcas[3];
            int tipoN = stoi(tipo);
            //CREAR MARCA 
            Marca marcaj(dia, hora, tipoN);
            //AGREGAR MARCA AL VECTOR MARCA
            Marcas.push_back(marcaj);
        }
    }
}

void Usuario::Informe(Datos_Turnos lista_de_turnos){
    ofstream salida;
    string filename = "salida/" + Identificador + ".txt";
    salida.open(filename, ios::out);
    if(salida.fail()){
        cout << "No se pudo crear el archivo de salida : Verifique que las carpetas esten correctas";
        exit(1);
    }

    for(int i = 0; i < Planificador.size(); i++){
        //Primer valor a introducir son los dias de la planificacion
        salida << Planificador[i].Dia;
        salida << ";";     

        for(int j= 0 ; j < lista_de_turnos.Turnos.size(); j++){
            if(Planificador[i].Turno_ID == lista_de_turnos.Turnos[j].Turno_id){
                salida << lista_de_turnos.Turnos[j].Hora_inicio;
                salida << ";";
                salida << lista_de_turnos.Turnos[j].Hora_fin;
                salida << ";";
            }

        }
        //Verificar que todo cumpla los requisitos
        for(int j = 0; j < lista_de_turnos.Turnos.size(); j++){
            lista_de_turnos.Turnos[j].TotalHoras();
        }
        string totalMinutosA;
        for(int j = 0; j < Marcas.size()-1; j++){
            if((Marcas[j].Dia == Planificador[i].Dia) && (Marcas[j].Tipo == 1)){
                vector<string> Hora_sucia1 = split(Marcas[j].Hora, ':');
                vector<string> Hora_sucia2 = split(Marcas[j+1].Hora, ':');
                int Hora1 = stoi(Hora_sucia1[0]);
                int Hora2 = stoi(Hora_sucia2[0]);
                int minutos1 = stoi(Hora_sucia1[1]); 
                int minutos2 = stoi(Hora_sucia2[1]);
                int totalH = ((Hora2-(Hora1+1))*60);
                int totalM1 = (60-minutos1)+minutos2;
                int totalM = totalH+totalM1;
                //totalMinutosA = to_string(totalM);
                for(int a = 0; a < lista_de_turnos.Turnos.size(); a++){
                    if(Planificador[i].Turno_ID ==  lista_de_turnos.Turnos_dia[a].Turno_id){
                        totalMinutosA = to_string(totalM+lista_de_turnos.Turnos_dia[a].Minutos_atraso_permitidos);
                    }
                    if(Planificador[i].Turno_ID ==  lista_de_turnos.Turnos_noche[a].Turno_id){
                        totalMinutosA = to_string(totalM-lista_de_turnos.Turnos_noche[a].Minutos_retiro_anticipados);
                    }
                }
            }
        }

        //Cuarto valor comparar si la planificacion y marca estan correctas osea si el trabajador fue
        int estado = 0;
        for(int j = 0; j < Marcas.size(); j++){
            if(Planificador[i].Dia == Marcas[j].Dia){
                salida << "True";
                salida << ";";
                salida << totalMinutosA;  //quinto valor los minutos trabajados
                estado = 1;
                break;                                
            }
        }
        if(estado == 0){
            for(int j = 0; j < Marcas.size(); j++){
                if(Planificador[i].Dia != Marcas[j].Dia){
                    salida << "False";  //quinto valor los minutos trabajados 
                    salida << ";";
                    salida << "0"; 
                    break;                                 
                }
            }
        }
        salida << endl; 
    }
    salida.close();
}

