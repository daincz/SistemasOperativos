/*
* Suma los números impares entre 0 y 20, es decir
* los números 1+3+5+7+9+11+13+15+17+19 = 100
*
* El primer hilo comprueba que el número es impar,
* si lo es deja que el segundo hilo lo sume,
* sino comprueba el siguiente número.
*
* Para compilar: gcc -o sem1 sem1.c -lpthread
*
*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t s1, s2;

int num=0, suma=0;

void *p1 ();
void *p2 ();

int main(){
    int error1, error2;
    pthread_t h1, h2;
    sem_init (&s2, 0, 0);
    sem_init (&s1, 0, 1);
    error1 = pthread_create (&h1, NULL, p1, NULL);
    error2 = pthread_create (&h2, NULL, p2, NULL);
    pthread_join (h1, NULL);
    pthread_join (h2, NULL);
    printf ("%s %d\n", "La suma es ->", suma);
    return 0;
}

void *p1(){
    int i;

    for (i=0; i<20; i++){
        sem_wait (&s1);

        printf ("HILO1: Número %d\n", i);

        if (i%2) {
            num=i;
            sem_post (&s2);
        }
        else sem_post (&s1);
    }
    pthread_exit(NULL);
}

void *p2(){

    int i;

    for (i=0; i<10; i++) {
        sem_wait (&s2);
        printf ("HILO2: Suma = %d + %d\n", suma, num);
        suma = suma+num;
        sem_post (&s1);
    }
    pthread_exit(NULL);
}

