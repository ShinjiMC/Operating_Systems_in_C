#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
   pid_t pid_hijo; int estado, x; long i, j; //pid_hijo es una variable para ID de un proceso

   if ( (pid_hijo= fork()) == -1){ /* Código PADRE: Error */ //Crea un proceso hijo y verifica si hay un error
      perror("Fallo al hacer fork()"); //Imprime el error y sale con codigo -1
      exit(-1);
   } else if (pid_hijo == 0) { /* Código HIJO */ //valida que el proceso hijo sea 0
      if ( execl("/bin/ls", "ls", "-l", NULL) < 0) { //Ejecuta el comando "ls -l" en la consola 
         perror("Fallo al ejecutar: ls"); //Muestra un mensaje de error al ejecutar el comando y retorna con -1
         exit(-1);
      }
   } else  /* Código PADRE */
      if ( (x=wait(&estado)) != pid_hijo) { //Espera a que el proceso hijo termine y obtiene su estado.
         fprintf(stdout, "PADRE: interrumpido por señal\n"); fflush(stdout); //Imprime un mensaje si el proceso hijo se interrumpe y limpia el buffer de salida
      }
   exit(0); /* Código PADRE e HIJO, aunque el hijo nunca pasará por aquí */ //Termina el proceso
}