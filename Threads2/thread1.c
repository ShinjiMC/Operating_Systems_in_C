#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
void *hola(void *arg) {//funcion puntero hola
    char *msg = "Hola";//una cadena Hola
    int i;
    for(i=0; i<strlen(msg); i++) {//Bucle según el tamaño de la cadena msg
        printf("%c", msg[i]);//imprime caracter de la cadena segun i
        fflush(stdout); //Limpia el buffer de salida
        usleep(1000000); //espera 1seg
    }
    return NULL ;//Retorna NULL
}
void *mundo(void *arg) {//funcion puntero mundo
    char *msg = " mundo";//una cadena mundo
    int i;
    for(i=0; i<strlen(msg); i++) {//Bucle según el tamaño de la cadena msg
        printf("%c", msg[i]);//imprime caracter de la cadena segun i
        fflush(stdout); //Limpia el buffer de salida
        usleep(1000000);//espera 1seg
    }
    return NULL ;//Retorna NULL
}
int main (int argc, char *argv[]) {
    pthread_t h1; // Declara hilo h1
    pthread_t h2;// Declara hilo h2
    pthread_create(&h1, NULL, hola, NULL);//crea el hilo h1 con la funcion hola
    pthread_create(&h2, NULL, mundo, NULL );//crea el hilo h2 con la funcion mundo
    pthread_join(h1, NULL);//Espera que finalice h1
    pthread_join(h2, NULL);//Espera que finalice h2
    printf("Fin \n");//Imprime en la terminal Fin
}