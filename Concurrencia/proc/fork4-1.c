#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int hijo (int numero){
    printf ("HIJO %d: Mi PID es %d mi padre es: %d\n", numero, getpid (),getppid());
    /* Ahora esperamos 20 segundos */
    sleep (20);
    printf("Hijo %d: Adios!\n", numero);
    return 0;
}

int main()
{
    int hijo1, hijo2, hijo3;

    printf ("PRINCIPAL: Mi PID es %d\n", getpid ());

    hijo1 = fork();

    if (hijo1){  // Si es el padre

        hijo2 = fork();

        if (hijo2){
             printf ("PADRE: Mi PID es %d\n", getpid ());
             printf ("PADRE: Adios\n");

        }
        else {

            hijo3 = fork();
            if(hijo3) {
                printf ("PADRE: Mi PID es %d\n", getpid ());
                printf ("PADRE: Adios\n");
            }
            else {
            if(hijo3) {
                printf ("PADRE: Mi PID es %d\n", getpid ());
                printf ("PADRE: Adios\n");
            }

            }
        }
    }
    else {


    }

    return 0;
}

