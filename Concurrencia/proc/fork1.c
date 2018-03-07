#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int hijo;

    printf ("PRINCIPAL: Mi PID es %d\n\n", (int) getpid ());
    hijo = fork();
    if (hijo){
        printf ("PADRE: Mi PID es %d y el de mi hijo es %d\n", getpid (), hijo);
        printf ("PADRE: Adios!\n\n");
    }
    else {
        printf ("HIJO: Mi PID es %d y el de mi padre es %d\n\n", getpid (), getppid());
        sleep (10);  //Esperamos 10 segundos
        printf ("HIJO: En este el PID de mi padre es %d\n\n", getpid (), getppid());
        printf("Hijo: ADIOS!\n");
    }

    return 0;
}
