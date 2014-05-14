//Kevin Yeap
/*========== Project Euler: Problem 12 ==========
Highly divisible triangular number
Problem 12

The sequence of triangle numbers is generated by adding the natural numbers. So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

Let us list the factors of the first seven triangle numbers:

     1: 1
     3: 1,3
     6: 1,2,3,6
    10: 1,2,5,10
    15: 1,3,5,15
    21: 1,3,7,21
    28: 1,2,4,7,14,28

We can see that 28 is the first triangle number to have over five divisors.

What is the value of the first triangle number to have over five hundred divisors?
=========================*/

/*========== program design notes ==========
two functions.
function one to loop through the sequence of triangle numbers
function two to check how many divisors there are. 

use long, we don't know how high these numbers will go.
=========================*/

/*========== program output ==========
        == Project Euler: Problem 12 ==

answer: 76576500
=========================*/

//need to improve the algorithm, current one takes 32 minutes to find the answer.

#include <iostream>
using namespace std;

long tri_num_div(long limit);
long num_of_divisors(long num);

int main() {
  long limit = 500;
  long result = tri_num_div(limit);
  
  cout << "\t== Project Euler: Problem 12 ==" << endl << endl; 
  cout << "answer: " << result << endl << endl; 
  
  return 0;
}

//cycle through all the triangle numbers and test for # of divisors, return when # of divisors is over limit
long tri_num_div(long limit) {
  long triangle_number = 0;
  
  for (long i = 1; num_of_divisors(triangle_number) < limit; i++) {
    triangle_number += i;
  }
  
  return triangle_number;
}

//return number of divisors from the input number
long num_of_divisors(long num) {
  int divisor_count = 0;
  long half = num/2;
  
  for (long i = 1; i < half; i++) {
    if ((num%i) == 0) { divisor_count++; }
  }
  divisor++; //+1 more to count itself.
   
  cout << num << " " << divisor_count << endl; 
  return divisor_count;
}