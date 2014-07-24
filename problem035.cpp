//Kevin Yeap
/*========== Project Euler: Problem 35 ==========
Circular primes
Problem 35
Published on 17 January 2003 at 06:00 pm [Server Time]

The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million?

=========================*/

/*========== program design notes ==========
cycle through all numbers in range, check if they are prime
if num is prime check if it is circular
=========================*/

/*========== program output ===========
        == Project Euler: Problem 35 ==

answer: 55
=========================*/

#include <cmath>
#include <iostream>
#define LIMIT 1000000 //limit is 1 million.

using namespace std;

int find_circular_primes(void);
bool is_circular_prime(int number);
bool is_prime(int num);

int main() {
  
  int result = find_circular_primes();
  
  cout << "\t== Project Euler: Problem 35 ==" << endl << endl; 
  cout << "answer: " << result << endl << endl; 
  
  return 0;
}

//returns number of circular primes up to the limit.
int find_circular_primes(void) {
  int count = 1; //account for the only even prime 2
  
  for (int i = 3; i < LIMIT; i++) {
    if (is_prime(i) && is_circular_prime(i)) { count++; cout << i << endl; }
  }
  
  return count;
};

//returns true is number is circular prime
bool is_circular_prime(int number) {
  int original = number;
  int num_dig = log10(number); //number of digits - 1
  int modified = 0; //this is the number that will be modified.
  
  while (modified != original) { //loops through all rotations
    modified = number%10;
    modified *= pow(10, num_dig);
    number = number/10;
    modified += number;
    number = modified; 
    if (!is_prime(modified)) { return false; }
  }
  
  return true;
}

//returns true if number is prime
bool is_prime(int num) {
  int root = sqrt(num) + 1;
  int i = 0;
  
  if ((num%2) == 0) { return false; }
  //checks odd numbers up to sqrt(num)
  for (i = 3; i < root; i += 2) {
    if ((num%i) == 0) { return false; }
  }
  
  return true;
}
