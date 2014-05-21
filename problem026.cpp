//Kevin Yeap
/*========== Project Euler: Problem 26 ==========
Reciprocal cycles
Problem 26

A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

    1/2	= 	0.5
    1/3	= 	0.(3)
    1/4	= 	0.25
    1/5	= 	0.2
    1/6	= 	0.1(6)
    1/7	= 	0.(142857)
    1/8	= 	0.125
    1/9	= 	0.(1)
    1/10	= 	0.1

Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
=========================*/

/*========== program design notes ==========
every rational number is either a terminating or repeating decimal
every repeating or terminating decimal is a rational number

using long division as an example for 1/n, we can see that a series will repeat once n is divided into the 
(remainder of the previous division*10) has already once been used. keep track of all numbers you *10 to divide num into 
again to get the next digit.
=========================*/

/*========== program output ==========
        == Project Euler: Problem 26 ==

answer: 983
=========================*/

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int find_longest_period(int limit); 
int calculate_decimal(int num); 
int find_period_length(vector<int> decimal); 

int main() {
  int limit = 1000;
  int result = find_longest_period(limit);
  
  cout << "\t== Project Euler: Problem 26 ==" << endl << endl; 
  cout << "answer: " << result << endl << endl; 
  
  return 0;
}

//find longest period of fractions between 1/2 ~ 1/limit
int find_longest_period(int limit) {
  int longest = 0;
  int period = 0;
  
  for (int i = 2; i < limit; i++) {
    period = calculate_decimal(i);
    if (period > longest) { longest = i; }
  }
  
  return longest;
}

////calculates next digit of the decimal and determines is the repetition is found.
int calculate_decimal(int num) {
  vector<int> decimal;
  int denom;
  int period_length;
  
  denom = 10 * (int)(log10(num) + 1);
  
  while(1) {
    
    decimal.push_back(denom);
    
    denom = (denom%num)*10; //calculate next number in the series.
    if (denom == 0) { return 0; }
    
    period_length = find_period_length(decimal); //check for a period
    if (period_length > -1) { return period_length; } 
  }
}

//find length of period of 1/num.
int find_period_length(vector<int> decimal) {
  int size = decimal.size();
  int last_index = size-1;
  
  for (int i = last_index-1; i >= 0; i--) {
    if (decimal[last_index] == decimal[i]) { return (size-i)-1; }
  }
  
  return -1;
}