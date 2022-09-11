#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <string.h>
#include "function.h"

using namespace std;

vector<string> split(string str, char delimiter) {
    //Dada una cadena de caracteres, devuelve un vector de strings
    //separada por el caracter indicado en delimiter
    vector<string> internal;
    stringstream ss(str); // Turn the string into a stream.
    string tok;
    while(getline(ss, tok, delimiter)) {        
        internal.push_back(tok);
    }
    return internal;
}

Datos AlmacenarDatos(void){
    //Almacena los datos dentro de una estructura dato
    const char *nombres[4] = { "entrada/Marcas.txt", "entrada/Planificacion.txt",
    "entrada/Turnos.txt", "entrada/Usuarios.txt"};
    Datos datos;
    for(int  i = 0; i <= 3; i++){
        vector<string> lines;
        string line;
        ifstream myfile(nombres[i]);
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
        {
            lines.push_back(line);
        }
            if(i == 0)datos.Marcas = lines;
            if(i == 1)datos.Planificacion = lines;
            if(i == 2)datos.Turnos = lines;
            if(i == 3)datos.Usuario = lines;
            myfile.close();
        }
    }
    return datos;
}

void ImprimirVector(vector<string> lines){
    //Impresion de los elementos del vector utilizando split separados por ";"
    for (int i = 0; i < lines.size(); i++) {
        vector<string> splitted = split(lines[i], ';');
        
        for (int j = 0; j < splitted.size(); j++) {
            //Por un error visual puede no imprimir el primer caracter
            //pero al guardarlo en una variable el valor esta completo           
            cout << splitted[j] << " ";
        }        
        cout << endl;
    }
}

Datos_Turnos GenerarTurnos(Datos info){
    Datos_Turnos datos_de_turno;
    vector<Turno> Lista_Turnos;
    vector<Turno_Dia> Lista_Turnos_Dia;
    vector<Turno_Noche> Lista_Turnos_Noche;
    for(int i = 0; i < info.Turnos.size(); i++){
        vector<string> VectorTurnos = split(info.Turnos[i], ';');
        string Turno_id = VectorTurnos[0];
        string Hora_inicio = VectorTurnos[1];
        string Hora_final = VectorTurnos[2];
        string tipo = VectorTurnos[4];
        Turno add_tn(stoi(Turno_id), Hora_inicio, Hora_final);
        Lista_Turnos.push_back(add_tn);
        if(tipo == "1"){
            string minutos_atraso_permitidos = VectorTurnos[3];
            Turno_Dia add_td(stoi(Turno_id), Hora_inicio, Hora_final, stoi(minutos_atraso_permitidos));
            Lista_Turnos_Dia.push_back(add_td);
        }else{
            string minutos_retiro_anticipados = VectorTurnos[3];
            Turno_Noche add_tn(stoi(Turno_id), Hora_inicio, Hora_final, stoi(minutos_retiro_anticipados));
            Lista_Turnos_Noche.push_back(add_tn);
        }
    }
    datos_de_turno.Turnos = Lista_Turnos;
    datos_de_turno.Turnos_dia = Lista_Turnos_Dia;
    datos_de_turno.Turnos_noche = Lista_Turnos_Noche;
    return datos_de_turno;
}
