#include <stdio.h>
#include <pthread.h>

pthread_t h1, h2;

void *hilo1 ();
void *hilo2 ();

int main() {
    pthread_create (&h1, NULL, hilo1, NULL);
    pthread_create (&h2, NULL, hilo2, NULL);
    pthread_join (h1, NULL);
    pthread_join (h2, NULL);
    return 0;
}

void *hilo1(){
    printf ("HILO1: Mi TID es %d\n", (int)pthread_self ());
    sleep (10);
    /* Esperamos 10 segundos */
    pthread_exit(NULL);
}

void *hilo2(){
    printf ("HILO2: Mi TID es %d\n", (int)pthread_self ());
    sleep (10);
    /* Esperamos 10 segundos */
    pthread_exit(NULL);
}
