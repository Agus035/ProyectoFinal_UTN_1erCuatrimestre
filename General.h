#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef GENERAL_H_INCLUDED
#define GENERAL_H_INCLUDED
#include "Juego.h"
#include "Usuario.h"
#include "pila.h"


///Prototipado

void pausarLimpiarInt();

Usuario *arr //arreglo global de usuarios, acá van a estar todos los usuarios, pero vamos a estar trabajando con 1 solo por sesión
//Supongo que la pos del arreglo / del archivo es la id, no?

#endif // GENERAL_H_INCLUDED
