#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main()
{
    int hijo;  // o pid_t hijo;
    int estado;

    printf ("PRINCIPAL: Mi PID es %d\n", getpid ());

    hijo = fork();
    if (hijo){
        printf ("PADRE: Mi PID es %d y el de mi hijo es %d\n", getpid (), hijo);
        wait(&estado);
        printf ("PADRE: Adios, mi hijo ha acabado con estado %d\n", estado);
    }
    else {
        printf ("HIJO: Mi PID es %d y el de mi padre es %d\n", getpid (), getppid());
        sleep (10);
        /* Esperamos 10 segundos */
    }

    return 0;
}
