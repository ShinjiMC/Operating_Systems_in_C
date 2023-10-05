
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
    int i;
    int j;
    pid_t rf; //inicializa variables
    rf = fork(); //crea el hijo del proceso creando ya dos procesos para ejecutar
    switch (rf) {
        case -1:
            printf("\nNo he podido crear el proceso hijo");//En caso que no se pueda crear hijo se da el mesajo de error
            break;
        case 0:
            i = 0;//le da valor a i de 0
            printf("\nSoy el hijo, mi PID es %d y mi variable i (inicialmente a %d) es par", getpid( ), i);//Muestra mensaje del ID del proceso hijo y la variable i que se esta iniciando en 0 que es par.
            for (j = 0; j < 5; j++) {//hace bucle de 5 veces con j
                i++;
                i++;//le suma 2 a i
                printf("\nSoy el hijo, mi variable i es %d", i);//muetras la variable de i con un mensaje inicando que viene por parte del proceso hijo
            };
            break;//sale del caso
        default:
            i = 1;//le da valor a i de 1
            printf("\nSoy el padre, mi PID es %d y mi variable i (inicialmente a %d) es impar", getpid( ), i);//Muestra mensaje del ID del proceso padre y la variable i que se esta iniciando en 1 que es impar.
            for (j = 0; j < 5; j++) {//hace bucle de 5 veces con j
                i++;
                i++;//le suma 2 a i
                printf("\nSoy el padre, mi variable i es %d", i);//muetras la variable de i con un mensaje inicando que viene por parte del proceso padre
            };
    };
    printf ("\nFinal de ejecucion de %d \n", getpid());//Manda un mensaje de finalizacion de ejecucion mostrando el ID del proceso actual
    exit (0);//sale del proceso retornando 0
}

/*
¿Son las variables enteras “i” y “j” del proceso padre las mismas que las del proceso hijo?
No, porque las variables para el proceso padre e hijo no son las mismas por el hecho de que cada uno tiene copias de las 
declaraciones de ”i” y ”j”. Por lo que cada proceso reserva memoria para darle los valores a ”i” de 1 o 0 y de ”j” de darle 
un valor de 0, siendo memoria separada entre procesos.
*/