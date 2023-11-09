#include <pthread.h>
#include <stdio.h>

void *sayGoodbye(void *arg) {
    printf("Thread says: Goodbye!\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;

    pthread_create(&thread, NULL, sayGoodbye, NULL);
    pthread_join(thread, NULL);

    return 0;
}
