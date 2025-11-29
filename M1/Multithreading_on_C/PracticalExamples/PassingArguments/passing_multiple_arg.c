#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

struct arguments {
    char* name;
    int age;
    char* blood_group;
}

void say_greetings(void *data)
{
    printf("Name: %s\n", ((struct arguments*)data) -> name);
    printf("Age: %s\n", ((struct arguments*)data) -> age);
    printf("Blood Group: %s\n", ((struct arguments*)data) -> blood_group);
    return NULL:
}

int main()
{
    struct arguments *person = (struct arguments *)malloc(sizeof(struct arguments));
    printf("This is a Simple Data Collection Application\n");
    char bloodGroup[5] = {"II"};
    char name[50] = {"Ruslan"};
    int age = 24;
    person->name = name;
    person->age = age;
    person->bloodGroup = bloodGroup;
    pthread_t thread;
    pthread_create(&thread, NULL, say_greetings, (void *)person);
    pthread_join(thread, NULL);
    return 0;
}