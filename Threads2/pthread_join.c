#include <pthread.h>
#include <stdio.h>

void *printNumbers(void *arg) {
    for (int i = 1; i <= 5; ++i) {
        printf("%d\n", i);
        sleep(1);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;

    pthread_create(&thread, NULL, printNumbers, NULL);
    pthread_join(thread, NULL);

    return 0;
}
