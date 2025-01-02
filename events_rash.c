// File Handling Program
// Program 6
//
// Rashil Shibakoti
// 11/16/2023
//
// CSC150 Fall 2023
// SDSU
//
// Ms. Kurtenbach
//
//


#include <stdio.h>

// declaring functions
void readEventData(FILE *pointer, int *day, int *attendance, float *cost);
float calculateRevenue(int attendance, float cost);
void printReportLine(int day, int attendance, float cost, float revenue);
void printSummary(int totalAttend, float totalRevenue, float avgCost);


int main() 
{
    FILE *inp;
    FILE *out;

    inp = fopen("/Users/rashilci132a/Desktop/FILE HANDLING/dec_events.txt", "r");
    out = fopen("/Users/rashilci132a/Desktop/FILE HANDLING/report.txt", "w");
    
    
    //fopen functino returns NULL if it fails to open the file.
    //when NULL is returned, the program ends
    if (inp == NULL || out == NULL)
    {
        printf("Error opening files. \n");
        return 1;
    }
    
    
    //declare and initialize variables
    int totalAttend = 0;
    float totalRevenue = 0;
    int day, attendance;
    float cost, revenue;

    
    
    // Print column headings in the report file
   // fprintf(out, "Date        Attendance        Cost Per Person        Gross Revenue\n");
    
    printf("%5s %12s %16s %12s \n", "Date | ", "Attendance | ", "Cost Per Person | ", "Gross Revenue");
    printf("\n");

    // display header
  
    
    // access each line of data in input file
    // while looop keeps running until it reaches the end of file
    while (!feof(inp))
    {
        //call the functino to scan everything in the line into day, attendance and cost variables
        readEventData(inp, &day, &attendance, &cost);
        
        //calculate revenue based on attendance and cost
        revenue = calculateRevenue(attendance, cost);
        
        //call a function to print each report line until the file ends
        printReportLine(day, attendance, cost, revenue);

        //calculate totals
        totalAttend += attendance;
        totalRevenue += revenue;
        printf("\n");
    }

    // call a function to display the summary
    printSummary(totalAttend, totalRevenue, totalRevenue / totalAttend);

    // close both files
    fclose(inp);
    fclose(out);


    return 0;
}


//functino to read the data from the txt file
void readEventData(FILE *pointer, int *day, int *attendance, float *cost) 
{
    fscanf(pointer, "%d %d %f", day, attendance, cost);
}

//functin to calculate the revenue based no attendance and cost
float calculateRevenue(int attendance, float cost) 
{
    return attendance * cost;
}

//function to print a line of report
void printReportLine(int day, int attendance, float cost, float revenue) 
{
    printf("%5d %10d %15.2f %16.2f\n", day, attendance, cost, revenue);
}

//function to print total attendance, total revenue and averag cost per person
void printSummary(int totalAttend, float totalRevenue, float avgCost) 
{
    printf("\n");
    printf("\n");
    printf("\n*****Summary*****\n");
    printf("\n");
    printf("Total Attendance: %d\n", totalAttend);
    printf("Total Revenue: $%.2f\n", totalRevenue);
    printf("Average Cost Per Person: $%.2f\n", avgCost);
}



