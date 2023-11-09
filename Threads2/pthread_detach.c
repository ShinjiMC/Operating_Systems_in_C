#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *countNumbers(void *arg) {
    for (int i = 1; i <= 5; ++i) {
        printf("%d\n", i);
        sleep(1);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;

    pthread_create(&thread, NULL, countNumbers, NULL);
    pthread_detach(thread); // Desvincular el hilo

    sleep(6); // Esperar tiempo suficiente para que el hilo termine
    return 0;
}

