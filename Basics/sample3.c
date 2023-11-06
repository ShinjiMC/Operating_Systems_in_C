#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main(void) {
   pid_t pid_hijo; int estado, x; long i, j; //pid_hijo es una variable para ID de un proceso

   if ( (pid_hijo= fork()) == -1){ /* Código PADRE: Error */ //Crea uno proceso hijo con fork y este le da a pid_hijo
      perror("Fallo al hacer fork()"); //Muestra un mensaje de error si 'fork()' falla.
      exit(-1);//Termina el codigo con error -1
   } else if (pid_hijo == 0) { /* Código HIJO */ //esto indica si el ID del proceso es un proceso hijo
      fprintf(stdout, "PID hijo: %ld\n", (long) getpid()); fflush(stdout); sleep(2); //Muestra el ID del proceso hijo, limpia el buffer de salida y hace que el proceso espere 2 segundos
   } else { /* Código PADRE */ 
      if ( (x=wait(&estado)) != pid_hijo) //espera a que el proceso hijo trmine y obtiene su estado
         fprintf(stdout, "PADRE: interrumpido por señal\n"); //Muestra un mensaje si el proceso hijo se interrumpe
      else
         fprintf(stdout, "PID padre: %ld / PID hijo: %ld / estado hijo: %d\n",(long) getpid(), (long) pid_hijo, estado); //Muestra el proceso padre, hijo y su estado del hijo
      fflush(stdout);
      //Limpia el buffer de salida
   }
   exit(0); /* Código PADRE e HIJO */ //Termina el proceso sin error
}
//Crea un proceso hijo, luego muestra el el ID del proceso hijo con su estado y su ID de padre
