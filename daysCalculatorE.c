#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/*
 *   Program name: daysCalculatorE.c
 *   Author: Aaron Bester
 *   Last Update: September 26, 2019
 *   Function: to print out number of days between the user given start and end date
 *   Compilation: gcc -ansi -o daysCalculatorE daysCalculatorE.c
 *   Execution: ./daysCalculatorE 05-01-2019 26-09-2021 include
 */

int main ( int argc, char *argv[] ) {

/* Time code copied from https://www.techiedelight.com/print-current-date-and-time-in-c/ */

/*Varible and array declarations*/

time_t now;
time(&now);
struct tm *local = localtime(&now);


char *monthName[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};


int monthLengthY1[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int monthLengthY2[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int dayOfYear[12] = {1,32,60,91,121,152,182,213,244,274,305,335};

int dayOfLeapYear[12] = {1,32,61,92,122,153,183,214,245,275,306,336};

/*"I know you are supposed to declare variables before coding but I need the if statement before this specific declaration
or else the program will try to read
from the argv that isn't there and result in a segmentation fault instead of giving the user the error"
*/

if(argc < 3){
  printf("Usage:./daysCalculatorE dd1-mm1-yyyy1 dd2-mm2-yyyy2 include \n");
  return(1);
}

char day1Str[3] = {argv[1][0],argv[1][1],'\0'};
char day2Str[3] = {argv[2][0],argv[2][1],'\0'};
char month1Str[3] = {argv[1][3],argv[1][4],'\0'};
char month2Str[3] = {argv[2][3],argv[2][4],'\0'};
char year1Str[5] = {argv[1][6],argv[1][7],argv[1][8],argv[1][9],'\0'};
char year2Str[5] = {argv[2][6],argv[2][7],argv[2][8],argv[2][9],'\0'};

int dd1 = 0;
int mm1 = 0;
int yyyy1 = 0;

int leapYear1Check = 0;
int leapYear2Check = 0;

int dd2 = 0;
int mm2 = 0;
int yyyy2 = 0;

int startDateNum = 0;
int endDateNum = 0;
int finalDateCount = 0;

/*Ensures that when the user doesn't include "include" in command line
 there isn't a segmentation fault
*/

if(argc < 4){
  argv[3] = "";
}

/*Takes the input from the user */

  dd1 = atoi (day1Str);
  dd2 = atoi (day2Str);
  mm1 = atoi (month1Str);
  mm2 = atoi (month2Str);
  yyyy1 = atoi (year1Str);
  yyyy2 = atoi (year2Str);

  /*Checks if user used today for start date or end date
  and sets the date to current date
  */

if(strcmp(argv[1],"today")== 0){
    /* Time code copied from https://www.techiedelight.com/print-current-date-and-time-in-c/ */
  dd1 = local->tm_mday;
  mm1 = local->tm_mon + 1;
 yyyy1 =local->tm_year + 1900;
}

if(strcmp(argv[2],"today")== 0){
  dd2 = local->tm_mday;
  mm2 = local->tm_mon + 1;
 yyyy2 =local->tm_year + 1900;
}

/*Leap year calculations*/

if(yyyy1 % 4 == 0 && yyyy1 % 100 != 0 || yyyy1 % 4 == 0 && yyyy1 % 400 == 0) {
  leapYear1Check = 1;
  monthLengthY1[1] = 29;
}

if(yyyy2 % 4 == 0 && yyyy2 % 100 != 0 || yyyy2 % 4 == 0 && yyyy2 % 400 == 0) {
  leapYear2Check = 1;
    monthLengthY2[1] = 29;
}

/* Error checking */

if(mm1 >12 || mm1 < 1){
  printf("Error - the month entered (%02d) is not in the proper range (1-12) \n", mm1);
  return(2);
}

if(mm2 >12 || mm2 < 1){
  printf("Error - the month entered (%02d) is not in the proper range (1-12) \n", mm2);
  return(3);
}

if(dd1 > monthLengthY1[mm1-1] || dd1 < 1){
  printf("Error - the date entered (%02d) is not in the proper range (1-%02d) \n", dd1, monthLengthY1[mm1-1] );
  return(4);
}
if(dd2 > monthLengthY2[mm2-1] || dd2 < 1){
  printf("Error - the date entered (%02d) is not in the proper range (1-%02d) \n", dd2, monthLengthY2[mm2-1] );
  return(5);
}

if (yyyy1 < 0) {
    printf("Error - the year entered (%02d) is not in the proper range (0-∞) \n", yyyy1 );
    return(6);
}

if (yyyy2 < 0) {
    printf("Error - the year entered (%02d) is not in the proper range (0-∞) \n", yyyy2 );
    return(7);
}

if(yyyy1>yyyy2){
  printf("Error - The start year (%04d) is greater than the end year (%04d) \n",yyyy1,yyyy2 );
  return(8);
}

/*Calculates the remaining days between the start date and the end of the start
 year and adds it to the final date count*/

if(yyyy1 != yyyy2){

 if (leapYear1Check == 1) {
    endDateNum = endDateNum + (366 - startDateNum);
  }
  else{
    endDateNum =endDateNum + (365 - startDateNum);
  }

/*While loop adds either 366 or 365 to the final date count
depending on whether or not the year is a leap year for the number of years
between the start year and the end year*/

  while ((yyyy1 +1) != yyyy2) {
yyyy1++;
    if(yyyy1 % 4 == 0 && yyyy1 % 100 != 0 || yyyy1 % 4 == 0 && yyyy1 % 400 == 0) {
      endDateNum = endDateNum + 366;
    }
    else{
   endDateNum = endDateNum + 365;
  }

  }
}

/*Calculates the number of the start and end date, subtracts
them and then adds that number to the finalDateCount
to get the number of days between */

if (leapYear1Check == 1){
  startDateNum = ((dayOfLeapYear[mm1-1])+(dd1));
}

else{
  startDateNum = ((dayOfYear[mm1-1])+(dd1));
}
if (leapYear2Check ==1){
    endDateNum = endDateNum + ((dayOfLeapYear[mm2-1])+(dd2));
}
else{
  endDateNum = endDateNum + ((dayOfYear[mm2-1])+(dd2));
}

finalDateCount= endDateNum-startDateNum;

/*Checks to see if the start date is larger than the end date*/

if(endDateNum < startDateNum) {
  printf("Error - the start date given (%02d-%02d-%04d) is after the end date given (%02d-%02d-%04d) \n",dd1,mm1,yyyy1,dd2,mm2,yyyy2);
  return(9);
}

/*Adds 1 if argv[3] equals include */

if(strcmp(argv[3],"include") == 0){
  finalDateCount++;
}

printf("%d\n",finalDateCount );

return(0);
}
