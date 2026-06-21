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
void menuInicio();
void menuOpcionesValidasVerificadas (int decision); //solamente es llamado cuando se verifica el usuario introduce una decisión válida
void menuOpcionesLoggeoRegistro(int decision, Usuario **arrUsuarios, int *cantUsuarios); //tiene solo las funciones de registro y loggeo (se hace después de muchas verificaciones)



#endif // GENERAL_H_INCLUDED
