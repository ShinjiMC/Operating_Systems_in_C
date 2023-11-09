#include <pthread.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void *infiniteLoop(void *arg) {
    while (1) {
        printf("Thread is running...\n");
        sleep(1);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, infiniteLoop, NULL);
    sleep(3);
    pthread_kill(thread, SIGTERM);
    pthread_join(thread, NULL);
    return 0;
}
