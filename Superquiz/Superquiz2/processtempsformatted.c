#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

//WHY DO THINGS NOT PRINT IN THE TERMINAL IF THEY DONT END WITH \n
// WHY ARE VARIABLES ALWAYS FILLED WITH SHIT UPON INITIALIZATION

/*
The only columns of relevance to us here are Date (NZST) and Tmax(C).
You may assume that they are always in columns 2 and 3 respectively and you may ignore the first two lines of that section.
Tmax is the maximum temperature recorded throughout the 24 hour period.
*/

#define MAX_INPUT_LINE_LENGTH 500
#define MAX_LENGTH_STATION_NAME 30

typedef struct daily_weather_s WeatherReport;

struct daily_weather_s {
    char Year[5];
    char Month[5];
    char Day[3];

    double Temperature;
    WeatherReport* next;
            // Pointer to next student in a list
};

WeatherReport ReportSpace[MAX_INPUT_LINE_LENGTH];
int firstFree = 0;

char* strchrn(char* s, int c, int n)
{
    //takes in char* pointer , letter to search for, c  and  which instance of c to return
    int occurrence = 0;
    if (n <= 0) {
        return NULL;
    }
    while (occurrence != n) {
        //edge cases: i reach end of list not enough occurrences
        if (*s == '\0') {
            return NULL;
        } else {
            //if letter im searching for matches letter in pointer
            if (*s == c) {
                occurrence++;
            }
        }
        s++;
    }
    //return the pointer to the nth iteration of c
    return s - 1;
}

WeatherReport* GenerateWeatherReport(const char* Year, const char* Month, const char* Day, const double Temp)
{
    WeatherReport* Report = NULL;
    //printf("%s", student->firstname);
        Report = &ReportSpace[firstFree];
        firstFree += 1;
        strncpy(Report->Year, Year, 20);
        Report->Year[4] = '\0';  // Make sure it's terminated
        strncpy(Report->Month, Month, 20);
        Report->Month[2] = '\0';  // Make sure it's terminated
        strncpy(Report->Day, Day, 20);
        Report->Day[2] = '\0';  // Make sure it's terminated
        Report->Temperature = Temp;
        //printf("Report->year is %s Report->Month is %s Report->Day is %s Report->Temperature is %f\n",  Report->Year, Report->Month, Report->Day, Report->Temperature);
        Report->next = NULL;
        //Report->Temp[MAX_INPUT_LINE_LENGTH - 1] = '\0';  // do i need to terminate a double?
        //Report->studentId = studentId;
        //Report->next = NULL;
        return Report;
    }

WeatherReport* readOneValue(FILE* file)
//processing file here
//read one line of file
//extract site name
//extract date, 2 day timest
//returns weather struct with date month year
{
    WeatherReport* OneWeatherInstance = 0;       // Pointer to a student record from the pool
    // if line is empty
    //return
    char buffer[MAX_INPUT_LINE_LENGTH];

    char* line;
    line = fgets(buffer, MAX_INPUT_LINE_LENGTH, file);
    if (line == NULL || *line == '\n') {

        return NULL;
    }


    char* startofdate = strchrn(line, ',', 1) + 1;
    char* startoftemp = strchrn(line, ',', 2) + 1;
    //help
    //printf("this is line %s\n", line);
    //printf("this is startofdate %s startoftemp %s \n", startofdate, startoftemp );
    char Year[5] = {0};
   // printf("Year before memcpy is %s\n", Year);

    memcpy(Year, startofdate, 4);
    startofdate += 4;
    //printf("Year after memcpy  is %c%c%c%c\n", Year[0], Year[1], Year[2], Year[3]);
    char Month[3] = {0};
    memcpy(Month, startofdate, 2);
    startofdate += 2;
    //printf("Month after memcpy  is %c%c\n", Month[0], Month[1]);
    char Day[3] = {0};
    memcpy(Day, startofdate, 2);
    startofdate += 2;
    //printf("Day after memcpy  is %c%c\n", Day[0], Day[1]);

    char unconvertedTemp[5];
    memcpy(unconvertedTemp, startoftemp, 4);
    //printf("unconvertedTemp after memcpy  is %c%c%c%c whole thing is %s \n", unconvertedTemp[0], unconvertedTemp[1], unconvertedTemp[2], unconvertedTemp[3], unconvertedTemp);

    unconvertedTemp[4] = '\0';
    //printf("unconvertedTemp after memcpy  is %c%c%c%c whole thing is %s \n", unconvertedTemp[0], unconvertedTemp[1], unconvertedTemp[2], unconvertedTemp[3], unconvertedTemp);

    //terminate it before making it into a double?
    double Temp = atof(unconvertedTemp);
    OneWeatherInstance = GenerateWeatherReport(Year, Month, Day, Temp);    //check if this address of temp is correct************
    //printf("firstname %s lastname %s studentID %d\n", buffer, commaPos1 + 1, id);

    //student= newStudent(buffer, commaPos1 + 1, identification);
    // Oops, a heap of code seems to have gone missing here.
    return OneWeatherInstance;
}


WeatherReport* readWeather(FILE *file, double threshhold)
{
    WeatherReport* first = NULL;     // Pointer to the first student in the list
    WeatherReport* Head = NULL;
    //char* last = NULL;
    //strchrn(last, '\n', 1);      //( \n is also 10 in ascii Pointer to the last date to read in the list
    WeatherReport* weatherInstance = readOneValue(file);
    while (weatherInstance != NULL) {
            //printf("weatherInstance is %f,threshhold is %f\n", weatherInstance->Temperature, threshhold);
            if ((weatherInstance->Temperature) < threshhold) {
                //printf("weatherInstance is %f,threshhold is %f\n", weatherInstance->Temperature, threshhold);
                //less than 30 so i throw away
                //weatherInstance = readOneValue(file);
                } else {
                    if (first == NULL) {
                        //does this mean first is a pointer to weatherinstance? yes i think
                        first = Head = weatherInstance;
                        first->next = Head;
                    } else {
                    Head->next = weatherInstance;
                    //printf("Head is %s%s%s\n",  Head->Year, Head->Month, Head->Day);
                    Head = Head->next;
                    }
                }

            weatherInstance = readOneValue(file);
        }
    //first[i] = 0+;

    return first;
}





char* get_line(char* outputPointer, int linetoread, FILE*inputFile) {
    //returns pointer to the weather station name
    for (int counter = 0; counter != (linetoread - 1); counter++) {
        char useless[600];
        fgets(useless, MAX_INPUT_LINE_LENGTH , inputFile);


    }
    fgets(outputPointer, MAX_INPUT_LINE_LENGTH , inputFile);
    return outputPointer;
}

void printReport(WeatherReport* weatherSummary, char* sitename, double maxTemp)
//takes in the list of required weathers to print as well as sitename
{
    int i = 0;
    printf("Dates when %0.1f C was reached at ", maxTemp);
    for (; sitename[i] != ','; i++) {
    printf("%c", sitename[i]);
    }
    puts("\n");
    //printf("%s %s %s %f\n", weatherSummary->Year,  weatherSummary->Month,  weatherSummary->Day,  weatherSummary->Temperature);
    puts("   Date       MaxTemp");
    //WHY IS THIS NOT WHILE WEATHERSUMMARY->NEXT != NULL????????????????????????
    while (weatherSummary != NULL || weatherSummary->next != 0) {

        printf("%s/%s/%s     %0.1f C\n", weatherSummary->Day,  weatherSummary->Month,  weatherSummary->Year,  weatherSummary->Temperature);
        weatherSummary = weatherSummary->next;
    }




}

int main(int argc, char* argv[])
{
/*
    argc = 3;
    argv[3] = ("processtemps" "kierantest.txt" "30.0");
*/
    FILE* inputFile = fopen(argv[1], "r");
    if(argc != 3) {
        fprintf(stderr, "Usage: processtemps filename threshold\n");
        return EXIT_FAILURE;
    } else if (inputFile == NULL) {
        fprintf(stderr, "File '%s' not found\n", argv[1]);
        return EXIT_FAILURE;
    }
    else {
        double threshhold = atof(argv[2]);
        //printf("%f\n", threshhold);
        //i use line to get pointer to the line with sitename
        char sitename[MAX_LENGTH_STATION_NAME] = {0};
        get_line(sitename, 3,inputFile);
        //i use this line to get pointer to line 10 where data starts so i can start processing
        //char* startofdata[MAX_INPUT_LINE_LENGTH];
        char datastart[300] = {0};
        get_line(datastart, 6, inputFile);
        WeatherReport* weatherSummary = readWeather(inputFile, threshhold);
        printReport(weatherSummary, sitename, threshhold);
    }
}

