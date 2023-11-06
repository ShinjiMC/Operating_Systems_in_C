#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(void) {
   pid_t pid; //pid es una variable para ID de un proceso
   int var= 0;
   printf("PID antes de fork(): %d\n", (int) getpid()); //Muestra el ID del proceso actual antes de realizarle cambios
   if ( (pid = fork()) > 0 ) { //Si el ID del proceso del fork es mayor a 0
      printf ("PID del padre: %d\n", (int) getpid()); //Muestra el ID del proceso actual indicando que es proceso padre
      var++;
   } else {
      if (pid == 0) //Si el ID del proceso del fork es igual a 0
         printf ("PID del hijo: %d\n", (int) getpid()); //Muestra el ID del proceso actual indicando que el proceso actual es hijo
      else
         printf ("Error al hacer fork()\n"); //Si 'pid' es menor a 0, da error. Ya que no es un proceso padre ni hijo
   }
   printf("Proceso [%d] -> var = %d\n", (int) getpid(), var); //Muestra el proceso actual y el valor de var
}
//Con este proceso llega a realizar fork a un proceso padre para obtener un proceso hijo de este