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
