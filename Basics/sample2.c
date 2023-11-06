#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
   pid_t pid;  //pid es una variable para ID de un proceso
   int i, n= 4;

   for (i=0; i<n; i++)
      if ( (pid = fork()) < 0 ) break; // Crea un nuevo proceso y verifica si hubo un error al llamar a 'fork()', o sino termina el bucle.

   printf ("Proceso: %d / Padre: %d\n", (int) getpid(), (int) getppid()); // Muestra el ID del proceso actual y el ID del proceso padre.
}
//El codigo crea 4 procesos hijos y luego muestra por cada proceso creado su proceso padre origen, en caso de error con fork el programa termina.
