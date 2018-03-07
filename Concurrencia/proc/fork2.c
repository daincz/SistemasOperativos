#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main()
{
    int hijo;

    printf ("PRINCIPAL: Mi PID es %d\n", (int) getpid ());

    hijo = fork();
    if (hijo){
        printf ("PADRE: Mi PID es %d y el de mi hijo es %d\n", getpid (), hijo);
        wait (0);
        printf ("PADRE: Adios, mi hijo ha finalizado\n");
    }
    else {
        printf ("HIJO: Mi PID es %d y el de mi padre es %d\n", getpid (),getppid());
        sleep (5);  // Esperamos 5 segundos
    }
}
