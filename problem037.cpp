//Kevin Yeap
/*========== Project Euler: Problem 37 ==========
Truncatable primes
Problem 37
Published on 14 February 2003 at 06:00 pm [Server Time]

The number 3797 has an interesting property. Being prime itself, it is 
possible to continuously remove digits from left to right, and remain 
prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right 
to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left 
to right and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
=========================*/

/*========== program design notes ==========
loop through the primes if it finds a prime. check if it is truncatable.
add it to a total once it finds
11 primes stop checking for primes.
=========================*/

/*========== program output ===========
        == Project Euler: Problem 37 ==

answer: 748317
=========================*/

#include <cmath>
#include <iostream>
using namespace std;

int find_truncatable_primes(void);
bool is_prime(int num);
bool is_truncatable(int num);

int main() {
  
  int result = find_truncatable_primes();
  
  cout << "\t== Project Euler: Problem 37 ==" << endl << endl; 
  cout << "answer: " << result << endl << endl; 
  
  return 0;
}

//returns the sums of the only 11 truncatable primes.
int find_truncatable_primes(void) {
  int total = 0;
  int count = 0;
  
  for (int i = 11; count < 11; i+=2) {
    if(is_prime(i) && is_truncatable(i)) { 
      total += i;
      count++;
    }
  }
  return total;
}

//returns true if the number passed in is truncatable
bool is_truncatable(int num) {
  int left = num;
  int right = 0;
  
  for( int i = 1; left > 10; i++) { //test both truncating left and right side.
    int divider = pow(10, i);
    right = num%divider;
    left = num/divider;
    if(!is_prime(left) || !is_prime(right)) { return false; }
  }
  return true;
}

//returns true if number is prime
bool is_prime(int num) {
  int root = sqrt(num) + 1;
  int i = 0;
  
  if ((num < 2) || ((num != 2) && ((num%2) == 0))) { return false; }
  //checks odd numbers up to sqrt(num)
  for (i = 3; i < root; i += 2) {
    if ((num%i) == 0) { return false; }
  }
  
  return true;
}