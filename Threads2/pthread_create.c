#include <pthread.h>
#include <stdio.h>

void *printMessage(void *arg) {
    printf("Thread says: %s\n", (char *)arg);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    const char *message = "Hello, pthreads!";

    pthread_create(&thread, NULL, printMessage, (void *)message);
    pthread_join(thread, NULL);

    return 0;
}
