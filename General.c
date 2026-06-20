#include "General.h"

// sys cls y sys pause
void pausarLimpiarInt()
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

    menuOpcionesValidas(decision)
}

void menuOpcionesValidas (int decision) //solamente es llamado cuando se verifica el usuario introduce una decisión válida
{
    //lo primero que hay que hacer llegado a este punto es cargar el array que tenemos de usuarios

    int cantUsuarios = 0;

    if (decision != 3) //3 significa que el usuario quiere salir del programa, entonces no cargo el array en ese caso
    {
        Usuario *arr //array de usuarios va a existir a partir de ahora
        cantUsuarios = pasarUsuariosAArr();
    }

    switch (opcion)
    {
    case 1:
        printf("\nIngrese su nombre de usuario: "); //continuo creando esto después de crear el registro
        break;
    case 2:
        printf("\nIngrese el nombre de usuario (lo utilizara para logearse, no olvidar): ");
        fflush(stdin);

    }
}

void registroUsuario
