#include <pthread.h>
#include <stdio.h>

void *printThreadId(void *arg) {
    pthread_t tid = pthread_self();
    printf("Thread ID: %lu\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;

    pthread_create(&thread, NULL, printThreadId, NULL);
    pthread_join(thread, NULL);

    return 0;
}
