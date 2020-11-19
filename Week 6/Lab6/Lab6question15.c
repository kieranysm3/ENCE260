#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct {
    char* name;
    int age;
    double height;
} Person;

Person* newPerson(char* name, int age, double height)
{
    Person* newHuman = malloc(sizeof(Person));
    char* personName = malloc(sizeof(char) * strlen(name) + 1);
    strncpy(personName, name, sizeof(char) * strlen(name));
    newHuman->name = personName;
    newHuman->name[strlen(name)] = '\0';
    newHuman->name = personName;
    newHuman->height = height;
    newHuman->age = age;
    return newHuman;

}


void freePerson(Person* person)
{
    free(person->name);
    free(person);
}

int main(void)
{
    Person* employee = newPerson("Billy", 30, 1.68);
    printf("%s is age %d and is %.2f m tall\n", employee->name, employee->age, employee->height);
    freePerson(employee);


}
