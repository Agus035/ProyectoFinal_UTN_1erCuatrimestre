#include "Usuario.h"
#include "Juego.h"

char matAdmin[2][LIMITE] = {"admin", "admin"}; //un usuario y una contraseña
//matAdmin[0] = username
//matAdmin[1] = password


///Main
int main()
{
//*********************************************
    //guardarJuegosEnArchivo(JUEGOSTIENDA, "a+b");//Simulamos los juegos que existen en la aplicacion,
//*********************************************
//    guardarJuegosEnArchivo(JUEGOSTIENDA, "ab");
//    leerJuegosDeTienda(JUEGOSTIENDA);

    leerJuegosOrdenadosNombreTienda(JUEGOSTIENDA);
    return 0;
}
