#include <stdio.h>

// ****************************
typedef struct queue_struct QueueElement;


struct queue_struct {
    char* username;
    QueueElement* next;

};



QueueElement* appendToQueue(QueueElement* firstpointer, QueueElement* addedelement)
{
    if (firstpointer == NULL) {
        firstpointer = addedelement;
    } else {
        QueueElement* first = firstpointer;
        while (first->next != NULL) {
            first = first->next;
        }
    first->next = addedelement;
    }
    return firstpointer;

}




// ****************************

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
    QueueElement stud1 = {"first", NULL};
    QueueElement stud2 = {"second", NULL};
    QueueElement stud3 = {"third", NULL};

    queue = appendToQueue(queue, &stud1);
    queue = appendToQueue(queue, &stud2);
    queue = appendToQueue(queue, &stud3);
    printQueue(queue, "after appending 3 students");
}
