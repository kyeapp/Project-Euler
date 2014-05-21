//Kevin Yeap
/*========== Project Euler: Problem 10 ==========
Summation of primes
Problem 10

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
=========================*/

/*========== program design notes ==========
We can use the check_prime function we wrote in problem 7.
check_prime function written for problem 7 takes 7 minutes for this problem.

optimizing prime checking. When checking to see if n is prime we only need to check factors 
up to the square root of n any numbers after that would have to be multiplied by another number under 
sqrt(n) to get n. and not all numbers under n need to be divided. only the prime numbers under sqrt(n)
need to be checked.

time improve from 7 minutes to .5 seconds.
=========================*/

/*========== program output ==========
        == Project Euler: Problem 10 ==

answer: 142913828922
=========================*/

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

long find_sum_primes(long limit);
long check_prime(vector<int>& primes, long num);

int main() {
  
  long limit = 2000000; //2 million
  long result = find_sum_primes(limit);



  cout << "\t== Project Euler: Problem 10 ==" << endl << endl; 
  
  cout << "answer: " << result << endl << endl; 
  
  return 0;
}

//
long find_sum_primes(long limit) {
  long total = 2; //start at two to account for the first prime.
    
  vector<int> primes; //vector to contain primes that are found.
  primes.push_back(2); //push 2 into the vector as the first prime.
    
  for (long i = 3; i < limit; i+=2) {
    //cout << i << endl;
    total = total + check_prime(primes, i);
    //cout << check_prime(primes, i) << endl; 
  }
 
  return total;
}

//returns num if it is prime. left out even number checks for speed.
long check_prime(vector<int>& primes, long num) {
  long size = primes.size();
  long root = sqrt(num) + 1;
  long i = 0;
  //cout << i << endl; 
  
  //check against all primes previously found
  while (i < size && primes[i] < root) {
    if ((num%primes[i]) == 0) { return 0; }
    i++;
  }
  
  //check up rest of odd numbers up to sqrt(num)
  for (i = primes[size-1]; i < root; i += 2) {
    if ((num%i) == 0) { return 0; }
  }
  
  primes.push_back(num);
  return num;
}