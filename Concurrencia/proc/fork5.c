#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int hijo (int numero){
    printf ("HIJO %d: Mi PID es %d\n", numero, getpid ());
    /* Esperamos 20 segundos */
    sleep (20);
    return 0;
}

int main()
{
    int hijo1, hijo2, hijo3;
    int estado1, estado2, estado3;

    printf ("PRINCIPAL: Mi PID es %d\n", (int) getpid ());

    hijo1 = fork();

    if (hijo1){

        hijo2 = fork();

        if (hijo2){

            hijo3 = fork();

            if (hijo3){
                printf ("PADRE: Mi PID es %d\n", getpid ());
                waitpid (hijo1, &estado1, WUNTRACED);
                //waitpid (hijo2, &estado2, WUNTRACED);
                //waitpid (hijo3, &estado3, WUNTRACED);
                printf ("PADRE: Adiós, mis hijos han acabado\n");
                printf ("PADRE: Hijo 1 acaba con estado %d\n", estado1);
                //printf ("PADRE: Hijo 2 acaba con estado %d\n", estado2);
                //printf ("PADRE: Hijo 3 acaba con estado %d\n", estado3);
            }
            else hijo (3);
        }
        else hijo (2);
    }
    else hijo (1);

    return 0;
}

