#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *custom_thread_function()
{
    for(int i = 0; i < 5; i++){
        printf("I am a custom thread function created by programmer.\n");
        sleep(1);
        if(i == 3){
            printf("My Jon is done. I now being terminated by programmer.\n");
            pthread_exit(NULL);
        }
    }
    return NULL;
}

int main()
{
    pthread_t thread;
    pthread_create(&thread, NULL, custom_thread_function, NULL);
    for(int i=0;i<5;i++){
        printf("I am the process thread created by compiler by default.\n");
        sleep(1);
    }
    return 0;
}