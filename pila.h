#ifndef PILA_H
#define PILA_H

#include <stdio.h>
#include <malloc.h>
#define Pila struct _Pila
#define P_Pila struct _Pila *

struct _Pila
{
    int valores[50]; //ya no es puntero, ahora es array de 50 (ahorra el dolor de cabeza de arrays dinámicos en usuario.h, además en las funciones el máximo de la pila es 50)
    int postope;
};

void inicpila(P_Pila p);
void apilar(P_Pila p, int dato);
void apilar(P_Pila p, int dato);
int desapilar(P_Pila p);
int tope(P_Pila p);
int pilavacia(P_Pila p);
void leer (P_Pila p);
void mostrar(P_Pila p);

#endif // PILA_H_INCLUDED
