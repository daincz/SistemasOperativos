#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *programa="ls";
char *argumentos[]={"ls", "-l", "/", NULL};

int main ()
{
    int hijo;
    hijo = fork ();
    if (hijo != 0)
        /* Este es el proceso padre */
        return hijo;
    else {
        /* Ejecutamos PROGRAMA, buscando en el PATH */
        execvp (programa, argumentos);

    }
    return 0;

}
