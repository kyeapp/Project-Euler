//Kevin Yeap
/*========== Project Euler: Problem 30 ==========
Digit fifth powers
Problem 30

Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

    1634 = 1^4 + 6^4 + 3^4 + 4^4
    8208 = 8^4 + 2^4 + 0^4 + 8^4
    9474 = 9^4 + 4^4 + 7^4 + 4^4

As 1 = 1^4 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
=========================*/

/*========== program design notes ==========
need function to return true or false if sum of nth powers of their digits is true.
feed function through a loop and if true add to the total
divide by 10 to get the next digit until the number is 0

the upper bound is a little tricky to find. You need to find the point at which the the increasing number will always be bigger than
the maximum possible sum of nth powers of the numbers digit. The increasing number will grow based on amount of digits it has
this means that it will grow exponentially, while the largest possible sum of nth powers is a linear growth.

need to use BigInt library if the upper bound gets too large.
=========================*/

/*========== program output ===========
        == Project Euler: Problem 30 ==

answer:  443839
=========================*/

#include <cmath>
#include <iostream>
//#include "BigIntegerLibrary.hh"
using namespace std;

bool is_sum_of_powers(int n, int power);
int sum_of_n_powers(int power);
int upper_bound(int power);

int main() {
  
  int result = sum_of_n_powers(5);
  
  cout << "\t== Project Euler: Problem 30 ==" << endl << endl; 
  cout << "answer: " << result << endl << endl; 
  
  return 0;
}

//adds up sum of powers given the power
int sum_of_n_powers(int power) {
  int lower = 10;//pow(10, num_of_digits)/10;
  int upper = upper_bound(power);//194980;
  int total = 0;
  
  for (int i = lower; i < upper; i++) {
    if(is_sum_of_powers(i, power)) { total += i; }
  }
  
  return total;
}

//returns 1 if the number is a sum of its nth powers
bool is_sum_of_powers(int n, int power) {
  int num = n; //holds the original number
  int temp = num; //number to convert to sum of powers
  int result = 0;
  
  while( temp != 0) {
    result += pow(temp%10, power);
    temp = temp/10;
  }
  
  if (result == num) { return true; }
  return false;
}

//finds an upper bound given a power
int upper_bound(int power) {
  int n = 1; 
  
  while(1) {
    if (pow(10, n) >= pow(9, power) * n) { break; }
    n++;
  }
  
  return pow(10, n);
}
  