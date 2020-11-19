/* prog.c
 * A variant of structexample3.c from lab 5 with the following changes:
 *
 * 1. The student struct now contains a firstname, a lastname and a student ID
 *    instead of a name and an age.
 * 2. The input data file is again a CSV file but the fields are firstname,
 *    lastname and student ID (an int).
 *
 * Richard Lobb, August 2019.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 80      // The longest line this program will accept
#define MAX_NUM_STUDENTS 500    // The maximum number of students this program can handle
#define MAX_NAME_SIZE 50        // The maximum allowable name length

// The declaration of the student record (or struct). Note that
// the struct contains the first and last names as arrays of characters.

typedef struct student_s Student;

struct student_s {
    char firstname[MAX_NAME_SIZE];
    char lastname[MAX_NAME_SIZE];
    int studentId;
    Student* next;              // Pointer to next student in a list
};

// Create a pool of student records to be allocated on demand

Student studentPool[MAX_NUM_STUDENTS];  // The student pool
int firstFree = 0;

// Return a pointer to a new student record from the pool, after
// filling in the provided first and last name and student ID fields.
// Returns NULL if the student pool is exhausted.
Student* newStudent(const char* firstname, const char* lastname, int studentId)
{
    Student* student = NULL;
    //printf("%s", student->firstname);
    if (firstFree < MAX_NUM_STUDENTS) {
        student = &studentPool[firstFree];
        firstFree += 1;
        strncpy(student->firstname, firstname, MAX_NAME_SIZE);
        student->firstname[MAX_NAME_SIZE - 1] = '\0';  // Make sure it's terminated
        strncpy(student->lastname, lastname, MAX_NAME_SIZE);
        student->lastname[MAX_NAME_SIZE - 1] = '\0';  // Make sure it's terminated
        student->studentId = studentId;
        student->next = NULL;
    }
    //printf(" I AM PRINT 2 firstname %s lastname %s student ID %d\n", student->firstname, student->lastname, student->studentId);
    return student;
}



bool precedes(const Student* student1, const Student* student2)
//return 1 if it is smaller than return 0 if it is greater than
{
    //compare first name return 0 if student 1 is smaller
    // if first name is the same, compare second name and return 1 if student 1 is smaller and 0 if student 2 is smaller
    int result = strcmp(student1->firstname, student2->firstname);
    //printf("result is %d student 1 is %s %s and student 2 is %s %s \n", result, student1->firstname, student1->lastname, student2->firstname, student2->lastname);
    if (result == 0) {
        result = strcmp(student1->lastname, student2->lastname);
        if (result > 0) {
            //printf("%s is bigger than %s\n", student2->firstname, student1->firstname);
            return 1;
        } else {
            //printf("%s %s is smaller than %s %s\n", student1->firstname, student1->lastname , student2->firstname, student2->lastname);
            return 0;
        }
    } else {
        if (result > 0) {
            //printf("result is %d student 1 is %s %s and student 2 is %s %s \n", result, student1->firstname, student1->lastname, student2->firstname, student2->lastname);
            return 1;
        } else {
            return 0;
        }
    }
    //printf("%s %s %d\n", student1->firstname, student1->lastname, student1->studentId);
    //printf("%s %s %d\n", student2->firstname, student2->lastname, student2->studentId);
}


Student* insert(Student* student, Student* first)
//i am taking in pointer to student as well as an empty studentlist
{
    //2 cases add in front or add behind depending on return value of precedes
    Student* Head = first;
    Student* Current = first;
    Student* Previous = NULL;
    //list only 1 item OK
    //current->next = NULL OK
    //traversing
    //item becomes new first  OK
    //insert item beween prev and current OK
    while (precedes(student, Current) == 1)
        //while student is greater than current
    {
        if (Current->next == NULL) {
            //this means i am the largest
            Current->next = student;
            return Head;
        }
        Previous = Current;
        Current = Current->next;
        //Traversing
    }
    //outside while loop means that student is smaller than current
    if (Previous == NULL) {
        //it means that the list has only 1 item and i am the smalleset
        student->next = Current;
        Head = student;
    } else {
        //i am inserting item between prev and current
        Previous->next = student;
        student->next = Current;
    }

    return Head;
}


// Read a single student from a csv input file with student first name in first column,
// second name in the second column and studentId in the last (third) column.
// Returns: A pointer to a Student record, or NULL if EOF occurs or if
// a line with fewer than 2 commas is read.
Student* readOneStudent(FILE* file)
{
    //i take in the POINTER to the first line of output from the csv file which is already a student struct?
    Student* student = NULL;       // Pointer to a student record from the pool
    char buffer[MAX_LINE_LENGTH];
    char* commaPos1 = NULL;
    char* commaPos2 = NULL;
    // if line is empty
    char* line = fgets(buffer, MAX_LINE_LENGTH, file);
    if ( line == NULL) {
        return NULL;
    }
    commaPos1 = strchr(buffer, ',');
    if (commaPos1 != NULL) {
        commaPos2 = strchr(commaPos1 + 1,',');
    }

    if ((commaPos1 == NULL) || (commaPos2 == NULL)) {
        return NULL;
    }
    int identification = atoi(commaPos2 + 1);
    *commaPos1 = '\0';
    *commaPos2 = '\0';
    //printf("firstname %s lastname %s studentID %d\n", buffer, commaPos1 + 1, id);

    student= newStudent(buffer, commaPos1 + 1, identification);
    // Oops, a heap of code seems to have gone missing here.


    return student;
}

// Reads a list of students from a given file. Input stops when
// a blank line is read, or an EOF occurs, or an illegal input
// line is encountered.
// Returns a pointer to the first student in the list or NULL if no
// valid student records could be read.
Student* readStudents(FILE *file)
{
    Student* first = NULL;     // Pointer to the first student in the list
    Student* last = NULL;      // Pointer to the last student in the list
    Student* student = readOneStudent(file);
    while (student != NULL) {
        if (first == NULL) {
            first = last = student;   // Empty list case
        } else {
            //initiallise new list to store sorted students
            first = insert(student, first);
        }
        student = readOneStudent(file);
    }

    return first;
}

// printOneStudent: prints a single student, passed by value
void printOneStudent(Student student)
{
    printf("%s %s (%d)\n", student.firstname, student.lastname, student.studentId);
}


// printStudents: print all students in a list of students, passed
// by reference
void printStudents(const Student* student)
{
    while (student != NULL) {
        //is my linked list connected in a circle or some shit
        //printf("i break here because student is %p\n", student->next);
        printOneStudent(*student);
        student = student->next;
    }
}

// Main program. Read a linked list of students from a csv file, then display
// the contents of that list.
int main(int argc, char* argv[])
{
    FILE* inputFile = fopen(argv[1], "r");
    if(argc != 2) {
        fprintf(stderr, "Usage: prog filename\n");
        return EXIT_FAILURE;
    } else if (inputFile == NULL) {
        fprintf(stderr, "File '%s' not found\n", argv[1]);
        return EXIT_FAILURE;
    }

    else {
        Student* studentList = readStudents(inputFile);
        //Student* StartOfStudentList = studentList;
        //i have 2 pointers Start and studentList pointing to the same address(start of array))
        printStudents(studentList);

        // The program could now do various things that make use of
        // the linked list, like deleting students and adding new ones,
        // but the program is already quite long enough!
    }
}
//./prog.c studlist.asst.txt
