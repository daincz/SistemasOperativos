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
    char mensaje[80];
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
        /* Cierre del descriptor de salida en el hijo */
        close(fd[1]);

        /* Leer algo de la tuberia... el saludo! */
        nbytes = read(fd[0], buffer, sizeof(buffer));
        printf("Hijo: %s", mensaje);
        printf("HIJO: Cadena recibida: %s\n", buffer);
        close (fd[0]);
        exit(0);
    }
    else {

        /* Proceso padre */
        /* Cierre de descriptor de entrada en el padre */
        close(fd[0]);
        /* Enviar el saludo via descriptor de salida */
        strcpy(mensaje, "Hola!");
        printf("PADRE: Envio a cadena a hijo\n");
        write(fd[1], mensaje, strlen(mensaje));
        close(fd[1]);
    }

    return 0;

}

