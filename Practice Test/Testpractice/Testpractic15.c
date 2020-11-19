#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char* description;
    float duration; // hours
    int priority;
} Task;




Task* newTask(char* description, float duration, int priority)
{
    Task* new = malloc(sizeof(Task));
    new->duration = duration;
    new->priority = priority;
    char* data1 = malloc((sizeof(char) * (strlen(description) + 1)));
    new->description = data1;
    strncpy(new->description, description, (sizeof(char) * strlen(description)));
    data1[strlen(description)] = '\0';
    return new;


}

void freeTask(Task* task)
{
    free(task->description);
    free(task);
}


int main(void)
{
Task* task = newTask("Studying for ENCE260", 2.5f, 1);
printf("Task \'%s\' (priority %d) takes %.1f hours.\n", task->description, task->priority, task->duration);
freeTask(task);
}
