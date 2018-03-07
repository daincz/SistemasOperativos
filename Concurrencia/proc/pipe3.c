/*
* COMUNICACION PADRE-HIJO A TRAVES DE TUBERIA
*   fd[0]: Lectura
*   fd[1]: Escritura
*
* Envio de datos PADRE->HIJO
*   Cerrar fd[0], escribir en fd[1]
*
* Envio de datos HIJO->PADRE
*   Cerrar fd[0], escribir en fd[1]
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int fd[2], nbytes;
    pid_t pid;
    char mensaje[] = "Hola hijo!\n";
    char buffer[80]="\0";

    pipe(fd);

    if((pid = fork()) == -1)
    {
        /* No se ha podido crear proceso hijo */
        perror("fork");
        exit(1);
    }

    if(pid == 0)
    {
        /* Proceso hijo */

        // calculo de la suma de 50 num
        int suma;

        /* Cierre del descriptor de salida en el hijo */
        close(fd[0]);

        /* Enviar el saludo via descriptor de salida */
        printf("PADRE: Envio a cadena a hijo");
        write(fd[1], suma, sizeof(suma));
        close(fd[1]);
    }
    else {

        /* Proceso padre */
        /* Cierre de descriptor de entrada en el padre */
        ///la suma de otros 50 num aleat
        suma


        close(fd[1]);

        /* Leer algo de la tuberia... el saludo! */
        nbytes = read(fd[0], buffer, sizeof(int));
        suma1 = *((int *)buffer);
        printf("HIJO: Cadena recibida: %s", suma+suma1);
        close (fd[0]);
        exit(0);
    }

    return 0;

}

