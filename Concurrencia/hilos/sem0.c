/*
* Programa PRODUCTOR-CONSUMIDOR
* Dada una cola circular compartida entre productor y consumidor
* se sincroniza su actualización mediante un semáforo s.
*
* Graduar tiempos de productor y consumidor mediante usleep.
* Inicialmente la cola circular está llena.
* El productor muestra por pantalla los números que escribe en la cola
* en la primera columna.
* El consumidor muestra por pantalla los números que lee de la cola
* a partir de la segunda columna.
* Para finalizar el programa pulsar CTRL+C.
*
* Para compilar: gcc -o sem0 sem0.c -lpthread
*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h> /* Para usleep, para graduar tiempos */

#define TAM 200
sem_t s;
typedef struct {
    int num[TAM];
    int inicio;
    int fin;
    enum {uno,dos} ultimo_avance;
} cola_circular;

cola_circular numeros;

void *productor ();
void *consumidor ();

int main(){
    int error1, error2;
    pthread_t h1, h2;
    sem_init (&s, 0, 1);
    /* Inicializamos valores de la cola */
    for (numeros.inicio=0; numeros.inicio<TAM; numeros.inicio++)
        numeros.num[numeros.inicio]=numeros.inicio;

    numeros.inicio = 0;
    numeros.fin = 0;
    numeros.ultimo_avance = dos;
    // Cola llena

    error1 = pthread_create (&h1, NULL, productor, NULL);
    error2 = pthread_create (&h2, NULL, consumidor, NULL);
    pthread_join (h1, NULL);
    pthread_join (h2, NULL);

    return 0;
}


void *productor () {
    int i=TAM;
    for (;;){
        sem_wait (&s);
        /* Si está lleno */
        if ((numeros.inicio==numeros.fin) && (numeros.ultimo_avance==dos))
            sem_post (&s);
        /* Si no está lleno */
        else {
            numeros.num[numeros.fin] = i;
            printf ("\n%d", numeros.num[numeros.fin]);
            numeros.fin = (numeros.fin + 1)%TAM;
            numeros.ultimo_avance = dos;
            i++;
            sem_post (&s);
            usleep (10000);
        }
    }
    pthread_exit(NULL);
}

void *consumidor () {
    for (;;) {
        sem_wait (&s);
        /* Si está vacio */
        if ((numeros.inicio==numeros.fin) && (numeros.ultimo_avance==uno))
            sem_post (&s);
        /* Si no está vacio */
        else {
            printf ("\t%d", numeros.num[numeros.inicio]);
            numeros.inicio = (numeros.inicio + 1)%TAM;
            numeros.ultimo_avance = uno;
            sem_post (&s);
            usleep (100);
        }
    }
    pthread_exit(NULL);
}
