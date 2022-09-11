#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <string.h>
#include "turno.h"

using namespace std;

//Creo una estructura que almacene los datos en vectores.
struct Datos
{
    vector<string> Marcas;
    vector<string> Planificacion;
    vector<string> Turnos;
    vector<string> Usuario;
};

//Estructura que recibe todos los vectores de turnos.
struct Datos_Turnos{
    vector<Turno> Turnos;
    vector<Turno_Dia> Turnos_dia;
    vector<Turno_Noche> Turnos_noche;
};

//Definicion de funciones.
vector<string> split(string str, char delimiter);
Datos AlmacenarDatos();
void ImprimirVector(vector<string> lines);
Datos_Turnos GenerarTurnos(Datos info);

#endif
