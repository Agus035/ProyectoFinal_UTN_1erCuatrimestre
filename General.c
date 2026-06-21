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

    menuOpcionesValidas(decision);
}

void menuOpcionesValidas (int decision) //solamente es llamado cuando se verifica el usuario introduce una decisión válida
{
    int cantUsuarios;

    if (decision != 3) //no se continua con el resto del programa si se eligió salirse (que es la opcion 3)
    {
        Usuario *arrUsuarios = NULL; //el array de usuarios va a existir a partir de ahora
        cantUsuarios = pasarUsuariosArchivoAArrDin(LISTAUSUARIOS, &arrUsuarios); //se llena el arreglo de usuarios (si existen) y se devuelven validos

        if (cantUsuarios == 0)
        {
            cantUsuarios = creacionArchivoDeUsuarios(&arrUsuarios); //cant usuarios es igual a -1 si hay error en malloc/abrir el archivo
        }

        if (cantUsuarios != -1)
        {
            switch (decision) //modularizar las opciones del switch
            {
            case 1:
                printf("\nIngrese su nombre de usuario: ");
                //tengo que hacer una función que verifique el usuario y contraseña que se ingrese coincida con alguno que se encuentre en el array de usuarios
                break;
            case 2:
                //aca iria la funcion de registro en usuario.h
                fflush(stdin);
            }
        }else //El else ocurre si aparece algún error al abrir el archivo/error en malloc
        {
            printf("\nHa ocurrido un error en la carga de usuarios. Cierre y abra el programa nuevamente.\n");
        }
    }else
    {
        printf("\nMuchas gracias por haber utilizado STOM. Vuelva pronto.\n"); //TERMINA EL PROGRAMA
    }
}





