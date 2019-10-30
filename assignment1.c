#include <stdio.h>
#include <stdlib.h>

/*
 *   Program name: Assignment1.c
 *   Author: Aaron Bester
 *   Last Update: September 17, 2019
 *   Function: to print out number of days between the user given start and end date
 *   Compilation: gcc -ansi -o assignment1 assignment1.c
 *   Execution: ./dates 23 8 2019
 */

int main ( int argc, char *argv[] ) {

char *monthName[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};

int monthLength[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int dayOfYear[12] = {1,32,60,91,121,152,182,213,244,274,305,335};

int dayOfLeapYear[12] = {1,32,61,92,122,153,183,214,245,275,306,336};

int dd1 = 0;
int mm1 = 0;
int year1 = 0;

int dd2 = 0;
int mm2 = 0;
int year2 = 0;

if(argc > 7){
  printf("", );
}

return(0);
}
