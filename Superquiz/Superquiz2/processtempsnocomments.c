#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/*
The only columns of relevance to us here are Date (NZST) and Tmax(C).
You may assume that they are always in columns 2 and 3 respectively and you may ignore the first two lines of that section.
Tmax is the maximum temperature recorded throughout the 24 hour period.
*/

#define MAX_INPUT_LINE_LENGTH 500
#define MAX_LENGTH_STATION_NAME 30

typedef struct daily_weather_s WeatherReport;

struct daily_weather_s {
    //Allocated 1 more
    char Year[5];
    char Month[3];
    char Day[3];

    double Temperature;
    WeatherReport* next;
};

WeatherReport ReportSpace[MAX_INPUT_LINE_LENGTH];
int firstFree = 0;

char* strchrn(char* s, int c, int n)
{
    //takes in char* pointer , letter to search for, c  and  which instance of c to return, n
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
    //Makes a WeatherReport struct from the data given and returns it.
    WeatherReport* Report = NULL;
    Report = &ReportSpace[firstFree];
    firstFree += 1;
    strncpy(Report->Year, Year, 20);
    Report->Year[4] = '\0';
    strncpy(Report->Month, Month, 20);
    Report->Month[2] = '\0';
    strncpy(Report->Day, Day, 20);
    Report->Day[2] = '\0';
    Report->Temperature = Temp;
    Report->next = NULL;
    return Report;
}

WeatherReport* readOneValue(FILE* file)
//processing file here
//read one line of file
//extract date, month, year and Temperature
//sends all the generated data to GenerateWeatherReport function to make the weatherstruct
//returns weather struct with date month year and Temp already initialized
{
    WeatherReport* OneWeatherInstance = 0;
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
    char Year[5] = {0};
    memcpy(Year, startofdate, 4);
    startofdate += 4;
    char Month[3] = {0};
    memcpy(Month, startofdate, 2);
    startofdate += 2;
    char Day[3] = {0};
    memcpy(Day, startofdate, 2);
    startofdate += 2;
    char unconvertedTemp[5];
    memcpy(unconvertedTemp, startoftemp, 4);
    unconvertedTemp[4] = '\0';
    double Temp = atof(unconvertedTemp);
    OneWeatherInstance = GenerateWeatherReport(Year, Month, Day, Temp);
    return OneWeatherInstance;
}


WeatherReport* readWeather(FILE *file, double threshhold)
{
    //i generate a linked list here which will return a pointer to first item in my list
    //this will then be printed using the printreport function
    WeatherReport* first = NULL;
    WeatherReport* Head = NULL;
    WeatherReport* weatherInstance = readOneValue(file);
    while (weatherInstance != NULL) {
        if ((weatherInstance->Temperature) < threshhold) {
        } else {
            if (first == NULL) {
                first = Head = weatherInstance;
                first->next = Head;
                //This line is to cover the edge case where there is only one item in the list.
                Head->next = NULL;
            } else {
                Head->next = weatherInstance;
                Head = Head->next;
            }
        }
        weatherInstance = readOneValue(file);
    }
    return first;
}

char* get_line(char* outputPointer, int linetoread, FILE*inputFile)
{
    //a function that just uses fgets to get to the linetoread specified from the file and returns
    //a pointer to it.

    for (int counter = 0; counter != (linetoread - 1); counter++) {
        char useless[MAX_INPUT_LINE_LENGTH];
        fgets(useless, MAX_INPUT_LINE_LENGTH, inputFile);


    }
    fgets(outputPointer, MAX_INPUT_LINE_LENGTH, inputFile);
    return outputPointer;
}

void printReport(WeatherReport* weatherSummary, char* sitename, double maxTemp)
//takes in the all the required inputs weatherSummary, name of the place , maxtemperature provided to format it nicely into the output required.
{
    int i = 0;
    printf("Dates when %0.1f C was reached at ", maxTemp);
    //The printing of the name was hardcoded as i didnt remember that i could have just inserted an EOF to the replace the ',' sorry
    for (; sitename[i] != ','; i++) {
        printf("%c", sitename[i]);
    }
    puts("\n");
    puts("   Date       MaxTemp");
    while (weatherSummary != NULL) {
        printf("%s/%s/%s     %0.1f C\n", weatherSummary->Day,  weatherSummary->Month,  weatherSummary->Year,  weatherSummary->Temperature);
        weatherSummary = weatherSummary->next;
    }




}

int main(int argc, char* argv[])
{
    //Takes in 3 arguments and generates a weather report based on the file provided(arg 2) and the maximum temperature(arg 3)
    FILE* inputFile = fopen(argv[1], "r");
    if(argc != 3) {
        fprintf(stderr, "Usage: processtemps filename threshold\n");
        return EXIT_FAILURE;
    } else if (inputFile == NULL) {
        fprintf(stderr, "File '%s' not found\n", argv[1]);
        return EXIT_FAILURE;
    } else {
        double threshhold = atof(argv[2]);
        char sitename[MAX_LENGTH_STATION_NAME] = {0};
        get_line(sitename, 3,inputFile);
        char datastart[MAX_INPUT_LINE_LENGTH] = {0};
        get_line(datastart, 6, inputFile);
        WeatherReport* weatherSummary = readWeather(inputFile, threshhold);
        printReport(weatherSummary, sitename, threshhold);
    }
}
