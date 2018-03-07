/*
* COMUNICACION A TRAVES DE TUBERIA
*   fd[0]: Lectura
*   fd[1]: Escritura
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>


int main(void)
{
    int fd[2];
    pid_t pid;
    char buffer0[80];
    char buffer1[80];
    char buffer2[80];
    int i;

    pipe(fd);

    if((pid = fork()) == 0)
    {
        /* HIJO1 */
        /* Envío de datos */
        do{

            for (i=0; i<80; i++) buffer1[i]='\0';

            fgets (buffer1, 80, stdin);
            printf (" HIJO1 -> HIJO2 \n");

            write(fd[1], buffer1, strlen(buffer1));

        } while (strncmp(buffer1,"quit",4));

        exit (0);
    }

    if ((pid = fork())==0) {
    /* HIJO2 */
    /* Recepción de datos */
        do {

            for (i=0; i<80; i++) buffer2[i]='\0';

            read(fd[0], buffer2, sizeof(buffer2));
            printf("HIJO2: %s", buffer2);

        } while (strncmp(buffer2, "quit",4));
        exit (0);
    }

    /* Proceso padre */
    /* Reenvío de datos */
    do {
        for (i=0; i<80; i++) buffer0[i]='\0';
        read(fd[0], buffer0, sizeof(buffer0));
        write(fd[1], buffer0, strlen(buffer0));
    } while (strncmp(buffer0, "quit",4));

    close (fd[0]);
    close(fd[1]);

    return 0;
}





