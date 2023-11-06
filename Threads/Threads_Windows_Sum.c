#include <stdio.h>
#include <Windows.h>

/* Structure for passing arguments to threads */
typedef struct {
    int a;
    int b;
} ThreadArgs;

DWORD WINAPI SumThread(LPVOID lpParam) {
    ThreadArgs* args = (ThreadArgs*)lpParam;
    int sum = args->a + args->b;
    printf("SumThread Result: %d + %d = %d\n", args->a, args->b, sum);
    return 0;
}

int main() {
    /* Data for arithmetic operations */
    ThreadArgs args1 = {10, 20};
    ThreadArgs args2 = {30, 40};

    /* Thread handlers */
    HANDLE thread1, thread2;

    /* Create two threads to perform the sum */
    thread1 = CreateThread(NULL, 0, SumThread, &args1, 0, NULL);
    thread2 = CreateThread(NULL, 0, SumThread, &args2, 0, NULL);

    /* Wait for both threads to finish */
    WaitForSingleObject(thread1, INFINITE);
    WaitForSingleObject(thread2, INFINITE);

    /* Close thread handles */
    CloseHandle(thread1);
    CloseHandle(thread2);

    return 0;
}
