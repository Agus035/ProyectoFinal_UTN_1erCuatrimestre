#include "General.h"

// sys cls y sys pause
void pausarLimpiarInt() //q hace esto ¿ Pausa y despues limpia la terminal 💔
{
    system("pause");
    system("cls");
}

void menuInicio()
{
    int decision;

    printf("--MENU--\n\n");
    printf("1. Iniciar sesion.\n");
    printf("2. Registrarse.\n");
    printf("3. Cerrar el programa.\n");

    do
    {
        printf("\nSu decision: ");
        while (scanf("%i", &decision) != 1)
        {
            printf("\nPor favor ingrese el numero de una de las opciones.\n");
            fflush(stdin); //lo que se ingresó que no es número sigue en stdin porque no se pudo leer, con esto lo limpio
            printf("Su decision: ");
        }

        if (decision > 3 || decision < 1)
        {
            printf("\nPor favor ingrese una opcion valida.\n");
        }
    }while(decision > 3 || decision < 1);

    menuOpcionesValidasVerificadas(decision);
}

void menuOpcionesValidasVerificadas (int decision) //solamente es llamado cuando se verifica el usuario introduce una decisión válida
{ //tal vez devolver un valor de error si salió todo mal (cant usuarios == -1), para que se corte el programa en función madre
    int cantUsuarios;

    if (decision != 3) //no se continua con el resto del programa si se eligió salirse (que es la opcion 3)
    {
        Usuario *arrUsuarios = NULL; //el array de usuarios va a existir a partir de ahora
        cantUsuarios = pasarUsuariosArchivoAArrDin(LISTAUSUARIOS, &arrUsuarios); //se llena el arreglo de usuarios (si existen) y se devuelven validos

        if (cantUsuarios == 0) //si no existe el archivo, se crea ahora
        {
            cantUsuarios = creacionArchivoDeUsuarios(&arrUsuarios); //cant usuarios es igual a -1 si hay error en malloc/abrir el archivo
        }

        if (cantUsuarios != -1)
        {
            menuOpcionesLoggeoRegistro(decision, &arrUsuarios, &cantUsuarios);
        }else //El else ocurre si aparece algún error al abrir el archivo/error en malloc
        {
            printf("\nHa ocurrido un error en la carga de usuarios. Cierre y abra el programa nuevamente.\n");
        }
    }else
    {
        printf("\nMuchas gracias por haber utilizado STOM. Vuelva pronto.\n"); //TERMINA EL PROGRAMA
    }
}

void menuOpcionesLoggeoRegistro(int decision, Usuario **arrUsuarios, int *cantUsuarios) //tiene solo las funciones de registro y loggeo (se hace después de muchas verificaciones)
{
        switch (decision) //modularizar las opciones del switch
        {
            case 1:
                printf("\nIngrese su nombre de usuario: ");
                //tengo que hacer una función que verifique el usuario y contraseña que se ingrese coincida con alguno que se encuentre en el array de usuarios
                break;
            case 2: ///IMPORTANTE: Hay que verificar que NO puedan existir usuarios del mismo nombre. [EDIT: creo que esa de "verificar usuario registrado" me sirve para eso].
                ///Entonces acá uso la función verificar nombre usuario registrado
                agregarUsuarioAArr (arrUsuarios, cantUsuarios); //Función crea y agrega a un nuevo usuario al array dinámico.
                //tal vez meter después de esto un do while por si falla el agregar usuario a archivo (que es lo que hace la función de abajo). Le pregunta al usuario si quiere intentar guardar su existencia en archivo de nuevo.
                guardarArrUsuariosEnArchivo(LISTAUSUARIOS, *arrUsuarios, *cantUsuarios); //Guarda el nuevo usuario en archivo
                break;
        }
}

void sistemaLoggeo(Usuario **arrUsuarios, int *cantUsuarios)
{
    char nombreUsuarioIngresado[VERIFICARLIMITE]; //51 para verificacion de caracteres org
    char contraseniaUsuarioIngresado[VERIFICARLIMITE]; //^

    do
    {
        printf("Ingrese el nombre de usuario: ");
        fflush(stdin);
        scanf("%50[^\n]", nombreUsuarioIngresado);
        if(strlen(nombreUsuarioIngresado) >= LIMITE)
            printf("\nPor favor evite intentar romper el programa.\n");

    }while(strlen(nombreUsuarioIngresado) >= LIMITE);

    do
    {

        printf("\nIngrese su contrasenia: ");
        fflush(stdin);
        scanf("%50[^\n]", contraseniaUsuarioIngresado);
        if(strlen(contraseniaUsuarioIngresado) >= LIMITE)
            printf("\nPor favor evite intentar romper el programa.\n");

    }while(strlen(contraseniaUsuarioIngresado) >= LIMITE);

    verificarUsuarioRegistrado(*arrUsuarios, *cantUsuarios, nombreUsuarioIngresado, contraseniaUsuarioIngresado);

}
