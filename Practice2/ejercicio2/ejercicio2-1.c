#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
int main() {
    int i;
    int fd1, fd2;
    const char string1[10]= "*********";
    const char string2[10]= "---------";
    pid_t rf;//declaramos variables
    fd1 = creat("ficheroA", 0666);//Crea o abre un archivo con el nombre ficheroA y con permisos de lectura y escritura para todos los usuarios, siendo descriptor el fd1
    fd2 = creat("ficheroB", 0666);//Crea o abre un archivo con el nombre ficheroB y con permisos de lectura y escritura para todos los usuarios, siendo descriptor el fd2
    rf = fork();//crea el hijo del proceso creando ya dos procesos para ejecutar
    switch (rf) {
        case -1:
            printf("\nNo he podido crear el proceso hijo");//En caso que no se pueda crear hijo se da el mesajo de error
            break;
        case 0:
            for (i = 0; i < 10; i++) {//hace bucle de 10 veces con i
                write(fd1, string2, sizeof(string2));//usamos el decriptor para escribir en el archivo, indicando el puntero de memoria de string2 y la cantidad de bytes a extraer
                write(fd2, string2, sizeof(string2));//usamos el decriptor para escribir en el archivo, indicando el puntero de memoria de string2 y la cantidad de bytes a extraer
                usleep(200000); /* (le damos una espera de 0.2 segundos) Abandonamos voluntariamente el procesador */
            }
            break;
        default:
            for (i = 0; i < 10; i++) {//hace bucle de 10 veces con i
                write(fd1, string1, sizeof(string1));//usamos el decriptor para escribir en el archivo, indicando el puntero de memoria de string1 y la cantidad de bytes a extraer
                write(fd2, string1, sizeof(string1));//usamos el decriptor para escribir en el archivo, indicando el puntero de memoria de string1 y la cantidad de bytes a extraer
                usleep(1000); /* (le damos una espera de 0.001 segundos) Abandonamos voluntariamente el procesador */
            }
    }
    printf("\nFinal de ejecucion de %d \n", getpid());//Mostramos un mensaje de finalizar la ejecucion del proceso con su id del proceso
    exit(0);//sale del proceso retornando 0
}