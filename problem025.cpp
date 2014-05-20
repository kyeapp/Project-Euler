//Kevin Yeap
/*========== Project Euler: Problem 25 ==========


The Fibonacci sequence is defined by the recurrence relation:

    F_n = F_n−1 + F_n−2, where F_1 = 1 and F_2 = 1.

Hence the first 12 terms will be:

    F_1 = 1
    F_2 = 1
    F_3 = 2
    F_4 = 3
    F_5 = 5
    F_6 = 8
    F_7 = 13
    F_8 = 21
    F_9 = 34
    F_10 = 55
    F_11 = 89
    F_12 = 144

The 12th term, F_12, is the first term to contain three digits.

What is the first term in the Fibonacci sequence to contain 1000 digits?

=========================*/

/*========== program design notes ==========
use BIGINT
just keep running Fibonacci using log10(num)+1 to measure the length of the number
=========================*/

/*========== program output ==========
        == Project Euler: Problem 25 ==

answer: 4782
=========================*/

#include <cmath>
#include <iostream>
#include <vector>
#include "BigIntegerLibrary.hh"

using namespace std;

BigUnsigned check_digits(BigUnsigned num);
BigUnsigned fibonacci(int digit_limit);
BigUnsigned big_pow(int x, int y);

int main() {
  int digit_limit = 1000;
  
  BigUnsigned result = fibonacci(digit_limit);
  
  cout << "\t== Project Euler: Problem 25 ==" << endl << endl; 
  cout << "answer: " << result << endl << endl; 
  
  return 0;
}

BigUnsigned fibonacci(int digit_limit) {
  BigUnsigned x = 1; //F_(n-2)
  BigUnsigned y = 1; //F_(n-1)
  BigUnsigned z = 0; //F_(n)
  BigUnsigned term = 2; //already have term 1 and 2
  BigUnsigned limit = big_pow(10, digit_limit-1);
  
  //cout << limit << endl; 

/*
  vector<BigUnsigned> fibonacci_term;
  fibonacci_term.resize(3);
  fibonacci_term[0] = 0; //empty to make terms align
  fibonacci_term[1] = 1; //first term is 1
  fibonacci_term[2] = 1; //second term is 1
  */
  while (z <= limit) {
    z = x+y;
    //fibonacci_term.push_back(z);
    term++;
    
    //cout << term << ": " << z << endl; 
    
    x = y;
    y = z;
  }
  
  return term;
}
  
  
//returns how many digits num has
/*
BigUnsigned check_digits(BigUnsigned num) {
  BigUnsigned limitz = 1 
}
*/
BigUnsigned big_pow(int x, int y) {
  BigUnsigned z = x; //compiler doesn't like my int * BIGINT though i thought it worked before.
  if (y == 0) return 1;
  return (z * big_pow(x, y-1));
}