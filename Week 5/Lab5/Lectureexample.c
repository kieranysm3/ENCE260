#include <stdio.h>
// struct student_s constitutes a type
// use type alias
//ability to initialise struct using comma seperated value inside braces
//can pass structs by value or by pointers

typedef struct student_s Student;
//type alias cab declare type as student you can have beter naming i guess another name for student_s.
// dot notation used when you have actual student but pointer notation is when you have an actual pointer

struct student_s {
    char* name;
    int age;
    Student* next;
};
//; is type declaration

void printOneStudent(Student student)
//passing struct by value not pointer
//now dot notation ecause its not a pointer
{
    printf(("%s (%d)\n"), student.name, student.age);
}

void printStudents(const Student* student)
{
    while (student != NULL) {
        //printf(("%s (%d)\n"), student->name, student->age);
        printOneStudent(*student);
        student = student->next;
    }
}

int main(int argc, char* argv[])
{
    Student student1 = {"Charlie", 16, NULL};
    Student student2 = {"Fred", 23, NULL};
    student1.next = &student2;
    printStudents(&student1);

}
