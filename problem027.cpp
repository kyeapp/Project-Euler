//Kevin Yeap
/*========== Project Euler: Problem 27 ==========
Euler discovered the remarkable quadratic formula:

n^2 + n + 41

It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39. 
However, when n = 40, 40^2 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when 
n = 41, 41^2 + 41 + 41 is clearly divisible by 41.

The incredible formula  n^2 − 79n + 1601 was discovered, which produces 80 primes for the 
consecutive values n = 0 to 79. The product of the coefficients, −79 and 1601, is −126479.

Considering quadratics of the form:

    n^2 + an + b, where |a| < 1000 and |b| < 1000

    where |n| is the modulus/absolute value of n
    e.g. |11| = 11 and |−4| = 4

Find the product of the coefficients, a and b, for the quadratic expression that produces the 
maximum number of primes for consecutive values of n, starting with n = 0.
=========================*/

/*========== program design notes ==========
two for loops to loop through all combinations of a and b
once once loop for a, θ(n)
once loop for b, θ(n)
last loop to check for primes, θ(sqrt(n))

This program shouldn't need a BigInt library
=========================*/

/*========== program output ===========
        == Project Euler: Problem 27 ==

answer: -59231
=========================*/

#include <cmath>
#include <iostream>
using namespace std;

int find_quadratic_eq(int limit);
int quadratic_chain(int a, int b);
int quadratic (int a, int b, int n); 
int is_prime(int num);

int main() {
  int limit = 1000;
  
  cout << "\t== Project Euler: Problem 27 ==" << endl << endl;
  
  int result = find_quadratic_eq(limit);
  
  cout << "answer: " << result << endl << endl; 
  
  return 0;
}

//the a and b of a quadratic equation that yields the highest number of consecutive primes numbers
int find_quadratic_eq(int limit) {
  int lower_bound = -limit+1; //general definition of lower bound, scalable
  int upper_bound = abs(limit-1); //general definition of higher bound, scalable

  int prime = 0; //this variable holds the number of consecutive primes of the current equation
  int longest_prime = 0; //this variable hold the longest number of consecutive primes.
  int longest_a = 0;
  int longest_b = 0;
  
  for (int a = lower_bound; a <= upper_bound; a++) { //loop through all a
    for (int b = lower_bound; b <= upper_bound; b++) { //loop through all b
      prime = quadratic_chain(a, b);
      
      if (prime > longest_prime) {
        longest_prime = prime;
        longest_a = a;
        longest_b = b;
      }
    }
  }
  
  cout << "\ta: " << longest_a << " b: " << longest_b << " length: " << longest_prime << endl << endl;
  return longest_a * longest_b; 
}

//returns length of the chain of primes created by the quadratic equation
int quadratic_chain(int a, int b) {
  int n = 0; //reset n
  int num = quadratic (a, b, n); //quadratic equation, with n as 0.
  
  while (is_prime(num) != 0) { //keep plugging in n until it finds a non-prime
    n++;
    num = quadratic (a, b, n); //computer next number
  }
  
  return n;
}

//returns n^2 + a*n + b
int quadratic (int a, int b, int n) {
  return n*n + a*n + b;
}

//returns num if prime and positive, else return 0.
int is_prime(int num) {
  int root = sqrt(num) + 1;
  int i = 0;
  
  if ((num%2 == 0 && num != 2) || (num < 0)) { return 0; } //2 is the only even number that is prime.
  
  //checks odd numbers up to sqrt(num)
  for (i = 3; i < root; i += 2) {
    if ((num%i) == 0) { return 0; }
  }
  
  return num;
}