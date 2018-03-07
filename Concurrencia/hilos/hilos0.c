#include <stdio.h>
#include <pthread.h>

void *hilo1 ();
void *hilo2 (void *in);

int main() {
    pthread_t h1, h2;
    int n=15;

    pthread_create (&h1, NULL, hilo1, NULL);
    pthread_create (&h2, NULL, hilo2, (void *)&n);

    sleep(2);
    return 0;
}

void *hilo1(){

    printf("Hilo 1\n");
    //sleep (2);
    /* Esperamos 10 segundos */

    pthread_exit(NULL);
}

void *hilo2(void *in){
    int x= *(int*)in;
    printf("Hilo 2: parametro enviado %d\n", x);
    //sleep (2);
    /* Esperamos 10 segundos */
    pthread_exit(NULL);
}
