#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct queue_struct QueueElement;

struct queue_struct {
    char* username;
    QueueElement* next;
};

QueueElement* appendToQueue(QueueElement* queue, QueueElement* appendee)
{
    QueueElement* head = queue;
    if (queue == NULL) {
        queue = appendee;
        return appendee;
    } else {
        while (queue->next != NULL) {
            queue = queue->next;
        }
            queue->next = appendee;
        }
    return head;
}

// Print the elements in the given queue of users preceded by the word
// 'Queue' and the supplied message.
void printQueue(QueueElement* queue, const char* message)
{
    QueueElement* current = queue;
    printf("Queue %s:", message);

    while (current != NULL) {
        printf(" %s", current->username);
        current = current->next;
    }
    printf("\n");
}


// Simple test of the student queue
int main(void)
{
    QueueElement* queue = NULL;
    QueueElement stud1 = {"abc24", NULL};
    QueueElement stud2 = {"pqr33", NULL};

    printQueue(queue, "at start");
    queue = appendToQueue(queue, &stud1);
    printQueue(queue, "after appending abc24");
    queue = appendToQueue(queue, &stud2);
    printQueue(queue, "after appending pqr33");
}

