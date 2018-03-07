/*
* Señales:
* Con SIGUSR1 hacemos que el programa ignore SIGINT
* Con SIGUSR2 hacemos que el programa responda ante SIGINT
*/

#include <signal.h>
#include <stdio.h>

void f_sigusr1 (){
    fprintf (stderr, "Señal SIGUSR1 recibida\n");
    fprintf (stderr, "Ignorando SIGINT\n");
    signal (SIGINT, SIG_IGN);
}

void f_sigusr2 (){
    fprintf (stderr, "Señal SIGUSR2 recibida\n");
    fprintf (stderr, "Restaurando SIGINT\n");
    signal (SIGINT, SIG_DFL);
}

int main (){
    signal (SIGUSR1, f_sigusr1);
    signal (SIGUSR2, f_sigusr2);
    while (1) pause ();
    return 0;
}
