//Kevin Yeap
/*========== Project Euler: Problem 3 ==========
Largest lp_factor factor
Problem 3

The lp_factor factors of 13195 are 5, 7, 13 and 29.

What is the largest lp_factor factor of the number 600851475143?
=========================*/

/*========== program design notes ==========
Since there is no way to tell if a number is a lp_factor unless it is tested. I will try a slightly
optimized approach to solving this problem. 
To solve I will factor out all lp_factor factors until the biggest one is left.
=========================*/

/*========== program output ==========
        == Project Euler: Problem 3 ==

answer: 6857
=========================*/

#include <iostream>
#include <cmath>
using namespace std;

long lp_factor(long num); //largest_prime_factor

int main() {
  long number = 600851475143; // maximum value of type int is 2,147,483,647 so we use a long 
  long result = lp_factor(number);

  cout << "\t== Project Euler: Problem 3 ==" << endl << endl; 
  cout << "answer: " << result << endl << endl; 
  
  return 0;
}

//returns largest prime factor of input number
long lp_factor(long num) {
  if ((num%2) == 0) { return lp_factor(num/2); }
  else {
    long limit = sqrt(num);
    
    for (long i = 3; i < limit; i += 2) {
      if ((num%i) == 0) { return lp_factor(num/i); }
    }
  }
  
  return num;
}