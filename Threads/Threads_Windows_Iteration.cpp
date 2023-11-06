#include <iostream>
#include <thread>
#include <windows.h> // Incluimos la cabecera de Windows para las funciones y tipos necesarios

// Función que se ejecutará en el primer thread
DWORD WINAPI FuncionThread1(LPVOID lpParam)
{
   for (int i = 0; i < 5; i++)
   {
      std::cout << "Thread 1 - Iteracion " << i << std::endl;
   }
   return 0;
}

// Función que se ejecutará en el segundo thread
DWORD WINAPI FuncionThread2(LPVOID lpParam)
{
   for (int i = 0; i < 5; i++)
   {
      std::cout << "Thread 2 - Iteracion " << i << std::endl;
   }
   return 0;
}

int main()
{
   // Crear dos handles para representar los threads
   HANDLE threadHandle1 = CreateThread(NULL, 0, FuncionThread1, NULL, CREATE_SUSPENDED, NULL);
   HANDLE threadHandle2 = CreateThread(NULL, 0, FuncionThread2, NULL, CREATE_SUSPENDED, NULL);

   // Iniciar la ejecución de los threads
   ResumeThread(threadHandle1);
   ResumeThread(threadHandle2);

   // Esperar a que ambos threads terminen
   WaitForSingleObject(threadHandle1, INFINITE);
   WaitForSingleObject(threadHandle2, INFINITE);

   CloseHandle(threadHandle1);
   CloseHandle(threadHandle2);

   std::cout << "Ambos threads han terminado." << std::endl;

   return 0;
}
