#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 *   Program name: daysCalculatorC.c
 *   Author: Aaron Bester
 *   Last Update: September 26, 2019
 *   Function: to print out number of days between the user given start and end date
 *   Compilation: gcc -ansi -o daysCalculatorC daysCalculatorC.c
 *   Execution: ./daysCalculatorC 20-03-2019 09-09-2019 include
 */

int main ( int argc, char *argv[] ) {

/*Varible and array declarations*/

char *monthName[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};

int monthLength[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int dayOfYear[12] = {1,32,60,91,121,152,182,213,244,274,305,335};

int dayOfLeapYear[12] = {1,32,61,92,122,153,183,214,245,275,306,336};

/*"I know you are supposed to declare variables before coding but I need the if statement before this specific declaration
or else the program will try to read from the argv that isn't there and result in a segmentation fault
 instead of giving the user the error"
*/

if(argc < 3){
  printf("Usage:./daysCalculatorC dd1-mm1-yyyy1 dd2-mm2-yyyy2 include \n");
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

int leapYearCheck = 0;

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

/*Leap year calculations*/

if(yyyy1 % 4 == 0 && yyyy1 % 100 != 0 || yyyy1 % 4 == 0 && yyyy1 % 400 == 0) {
  leapYearCheck = 1;
    monthLength[1] = 29;
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

if(dd1 > monthLength[mm1-1] || dd1 < 1){
  printf("Error - the date entered (%02d) is not in the proper range (1-%02d) \n", dd1, monthLength[mm1-1] );
  return(4);
}
if(dd2 > monthLength[mm2-1] || dd2 < 1){
  printf("Error - the date entered (%02d) is not in the proper range (1-%02d) \n", dd2, monthLength[mm2-1] );
  return(5);
}

if (yyyy1 < 0) {
    printf("Error - the year entered (%02d) is not in the proper range (0-∞) \n", yyyy1 );
    return(6);
}

if(yyyy1 != yyyy2){
  printf("Error - the starting year (%04d) is not equal to the ending year (%04d)\n",yyyy1,yyyy2 );
  return(7);
}

/*Calculates the number of the start and end date and subtracts
them to get the number of days between */

if (leapYearCheck == 1){
  startDateNum = ((dayOfLeapYear[mm1-1])+(dd1));
  endDateNum = ((dayOfLeapYear[mm2-1])+(dd2));
}

else{
  startDateNum = ((dayOfYear[mm1-1])+(dd1));
  endDateNum = ((dayOfYear[mm2-1])+(dd2));
}

finalDateCount=(endDateNum-startDateNum);

/*Adds 1 if argv[3] equals include */

if(strcmp(argv[3],"include") == 0){
  finalDateCount++;
}

/*Checks to see if the start date is larger than the end date*/

if(endDateNum < startDateNum) {
  printf("Error - the start date given is larger than the end date \n" );
  return(8);
}
printf("%d\n",finalDateCount );

return(0);
}
