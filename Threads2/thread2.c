#include <stdio.h>
#include <pthread.h>
#define N 8
#define M 16
const char *mensaje[2] = {"Hola Mundo", "Mundo Hola"};//un array de cadenas
const int cantidad[2] = {N, M};//un array de enteros definidos al inicio como 8 y 16 respectivamente
void imprime_mensaje(void *ptr) {//funcion imprime_mensaje 
    int i;
    int id;
    id = *(int *) ptr;//le da la desreferencia del puntero generico (void*) y lo devuelve como entero
    for(i=0; i<cantidad[id]; i++)//Bucle de n veces segun cantidad e id obtenido
        printf("%s\n",mensaje[id]);//imprime el mensaje del array según el param id
    return; //retorna la función
}

int main(int argc, char *argv[])
{
    pthread_t hilo0, hilo1;// Declara hilo0 y hilo1
    int id0=0, id1=1;//declara ids
    pthread_create(&hilo0, NULL, (void *) &imprime_mensaje, (void *) &id0);//crea el hilo0 con la funcion imprime_mensaje, y se ingresa como parametro el puntero de id0
    pthread_create(&hilo1, NULL, (void *) &imprime_mensaje, (void *) &id1);//crea el hilo1 con la funcion imprime_mensaje, y se ingresa como parametro el puntero de id1
    pthread_join(hilo0, NULL);////Espera que finalice hilo0
    pthread_join(hilo1, NULL);//Espera que finalice hilo1
    return 0;//retorna 0 en main
}