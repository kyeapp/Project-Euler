//Kevin Yeap
/*========== Project Euler: Problem 10 ==========
Summation of primes
Problem 10

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
=========================*/

/*========== program design notes ==========
We can use the check_prime function we wrote in problem 7.
This method apparently takes a while.

proposed optimize solution: Store all the primes we find and just divide by all the primes 
that we find and only if we go through the whole list then do we start dividing by numbers 
incremented by 2 from our largest known prime.
=========================*/

/*========== program output ==========
        == Project Euler: Problem 10 ==

answer: 142913828922
=========================*/
//current method takes about 7 minutes to find the answer.

#include <iostream>
using namespace std;

long find_sum_primes(long limit);
long check_prime(long num);

int main() {
  
  cout << "\t== Project Euler: Problem 10 ==" << endl << endl; 
  cout << "\tWarning: this program takes 7 minutes to execute" << endl;
  
  long limit = 2000000; //2 million
  long result = find_sum_primes(limit);
  
  cout << "answer: " << result << endl << endl; 
  
  return 0;
}

//
long find_sum_primes(long limit) {
  long total = 2; //start at two to account for the first prime.
    
  for (long i = 3; i < limit; i+=2) {
    //cout << i << endl;
    total = total + check_prime(i);
  }
 
  return total;
}

//returns num if it is prime. left out even number checks for speed.
long check_prime(long num) {
  long half = num / 2;
 
  for (long i = 3; i < half; i += 2) {
    if ((num%i) == 0) { return 0; }
  }
  
  return num;
}