//Kevin Yeap
/*========== Project Euler: Problem 19 ==========
Counting Sundays
Problem 19

You are given the following information, but you may prefer to do some research for yourself.

    1 Jan 1900 was a Monday.
    Thirty days has September,
    April, June and November.
    All the rest have thirty-one,
    Saving February alone,
    Which has twenty-eight, rain or shine.
    And on leap years, twenty-nine.
    A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
=========================*/

/*========== program design notes ==========
0 - 6, Sun - Sat
1 - 12, Jan - Dec

need function to find number of days in the passed in month, based on month and year.

leap year is ((year%4 == 0) && (year%100 != 0)) || (year%400 == 0)

need two loops one for year, one for month.
=========================*/

/*========== program output ==========
        == Project Euler: Problem 19 ==

answer: 171
=========================*/

#include <iostream>
#include "BigIntegerLibrary.hh"
using namespace std;

int count_days(void);
int find_num_days(int month, int year);

int main() {
  int result = count_days();
  
  cout << "\t== Project Euler: Problem 19 ==" << endl << endl; 
  cout << "answer: " << result << endl << endl; 
  
  return 0;
}

int count_days(void) {
  int f_day = 1; //first day of the month. set to monday on jan 1, 1900
  int num_days = 0;  //keeps of days to add to get to the 1st of the next month.
  int count = 0;
  for(int year = 1900; year <= 2000; year++) {
    for(int month = 1; month <= 12; month++) {
      num_days = find_num_days(month, year);
      f_day = (num_days+f_day)%7; // find what day it is of the next month
      if (f_day == 0 && year > 1900) count++;
    }
  }
  return count;
}

int find_num_days(int month, int year) {
  if (month == 1 || month == 3 || month == 5 || month == 7 || 
                    month == 8 || month == 10 || month == 12) {
    return 31;
  } else if ( month == 4 || month == 6 || month == 9 || month == 11) { 
    return 30;
  } else if (month == 2) {
    if (((year%4 == 0) && (year%100 != 0)) || (year%400 == 0)) return 29;
    return 28; //return 28 if not leap year.
  } else {
    return 0; // if the number is not 0 - 11 inclusive return 0;  
  }
}

//9/1901