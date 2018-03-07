#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int hijo (int numero){
    printf ("HIJO %d: Mi PID es %d\n", numero, getpid ());
    /* Ahora esperamos 400 segundos */
    sleep (400);
    return 0;
}

int main()
{
    pid_t hijo1, hijo2, hijo3;

    printf ("PRINCIPAL: Mi PID es %d\n", getpid ());

    hijo1 = fork();

    if (hijo1){

        hijo2 = fork();

        if (hijo2){

            hijo3 = fork();

            if (hijo3){

                printf ("PADRE: Mi PID es %d\n", getpid ());
                printf ("Tengo 3 hijos con los siguientes PID: \n");
                printf ("1) %d\n", hijo1);
                printf ("2) %d\n", hijo2);
                printf ("3) %d\n", hijo3);
                printf ("Matando hijo 1... Compruebalo\n"); kill(hijo1, SIGTERM);
                sleep (5);
                printf ("Matando hijo 2... Compruebalo\n"); kill(hijo2, SIGTERM);
                sleep (5);
                printf ("Matando hijo 3... Compruebalo\n"); kill(hijo3, SIGTERM);
                sleep (5);
                printf ("PADRE: Adios\n");
            }
            else hijo(3);
        }
        else hijo(2);
    }
    else hijo(1);

    return 0;
}

