#include <stdio.h>
#include <pthread.h>

void *say_greetings(void *input)
{
    printf("Hello %s\n", (char*)input);
    pthread_exit(NULL);
}

int main()
{
    char name[50] = {"Eva"};
    pthread_t thread;
    pthread_create(&thread, NULL, say_greetings, name);
    pthread_join(thread, NULL);
    return 0;
}