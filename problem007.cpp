//Kevin Yeap
/*========== Project Euler: Problem 7 ==========
10001st prime
Problem 7

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10,001st prime number?
=========================*/

/*========== program design notes ==========
I built off problem 3s code built to create check prime. nothing special about my program.
It takes about 1.5 second to get the answer my algorithm could probably be improved.

proposed optimize solution: Store all the primes we find and just divide by all the primes 
that we find and only if we go through the whole list then do we start dividing by numbers 
incremented by 2 from our largest known prime.
=========================*/

/*========== program output ==========
        == Project Euler: Problem 7 ==

answer: 104743
=========================*/

#include <iostream>
#include <cmath>
using namespace std;

int find_nth_prime(int num); //returns the nth prime
int check_prime(int number); //return number if prime

int main() {
  int target_position = 10001;
  int result = find_nth_prime(target_position);
  
  cout << "\t== Project Euler: Problem 7 ==" << endl << endl; 
  cout << "answer: " << result << endl << endl; 
  
  return 0;
}

//takes a position and returns the prime at the position.
int find_nth_prime(int target_position) {
  int position = 1; //position count starts at one to account for number two, the first prime which happens to be even.
  int i;

  for (i = 3; position < target_position; i += 2) {
    if (check_prime(i) != 0) { position++; }
  }
  
  return i-2; //-2 because after the loop, i gets incremented by 2 again.
}

//returns num if it is prime.
int check_prime(int num) {
  int limit = sqrt(num);
  
  for (int i = 3; i <= limit; i += 2) {
    if ((num%i) == 0) { return 0; }
  }
  
  return num;
}
