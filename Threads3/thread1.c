# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>

struct parametros {//estructura que almacena datos como el id, la matriz de reales y el escalar por el cual multiplicar con la matriz
    int id;
    float escalar;
    float matriz [3][3];
};
void init ( float m [3][3]) {//funcion qe recibe como parametro la matriz
    int i;
    int j;
    for (i=0; i<3; i++) {
        for ( j=0; j<3 ; j++) {
            m[i][j] = random()*100;// rellenamos los campos de la matriz con valores aleatorios
        }
    }
}
void * matrizporescalar(void *arg) { //funcion puntero que recibe a otra funcion puntero
    struct parametros *p; //puntero de tipo parametros
    int i;
    int j;
    p = (struct parametros *) arg; //le hace un cast a arg para definirlo como puntero de la estructura
    for ( i=0; i<3; i++) {
        printf ("Hilo %d multiplicando fila %d \n" , p->id , i);//Imprimo un mensaje con los valores de ID del hilo y el numero de fila
        for ( j=0; j<3; j++) {
            p->matriz[i][j] = p->matriz[i][j]*p->escalar;//Realizo la multiplicación de la fila con el escalar
            usleep(100000);//Detiene la ejecución del hilo actual por 0.1 segundos
        }
    }
}
int main (int argc, char *argv[]) {
    pthread_t h1;//Llamo al hilo h1
    pthread_t h2;//Llamo al hilo h1
    struct parametros p1; //defino como parametros a p1 y p2
    struct parametros p2;
    //Inicializo mis parametros de p1 y p2
    p1.id = 1;
    p1.escalar = 5.0;
    init(p1.matriz);
    p2.id = 2;
    p2.escalar = 10.0;
    init(p2.matriz);
    //Ejecuto con los hilos la funcion matrizporescalar dando como variable los parametros
    pthread_create(&h1, NULL, matrizporescalar, (void *)&p1);
    pthread_create(&h2, NULL, matrizporescalar, (void *)&p2);
    //Espera que finalice la ejecucion de los hilos
    pthread_join(h1, NULL);
    pthread_join(h2, NULL);
    printf ( "Fin\n"); //Imprime Fin
}