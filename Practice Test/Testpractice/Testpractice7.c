#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char* description;
    float duration; //hours
    int priority; //
} Task;


Task* newTask(char* description, float duration, int priority)
{
        Task* data1 = malloc(sizeof(Task));
        char* data2 = malloc((strlen(description) + 1) * sizeof(char));
        data1->description = data2;
        data1->duration = duration;
        data1->priority = priority;
        strncpy((data1->description), description, (strlen(description) * sizeof(char)));
        data1->description[strlen(description)] = '\0';
        return data1;
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

