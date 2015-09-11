//Kevin Yeap
/*========== Project Euler: Problem  ==========
We shall say that an n-digit number is pandigital if it makes use of all the 
digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists?
=========================*/

/*========== program design notes ==========
ways to approach this problem.

1.
find all permutations of digits 1 - n, 9 being 9,8,7, etc... until the largest pantigital prime is found.   O(n*n!)
brute force prime checking complexity   O(n(sqrt(n)));

2.
find all pandigital permutations    O(n*n!)
find all primes from 1 - 98765321   O(n(sqrt(n)))
sort both lists and find biggest common.

3.
find all primes from 1 - 987654321.  O(n(sqrt(n)))
check pandigital starting from largest prime until found. O(n)


Solution implementation.
Sieve of Eratosthenes to find primes, then check if they are panditigal.
run time complexity
O(Nlog log N) +  O(n)

space complexity O(n)  Acceptable since the number of primes are small.
=========================*/

/*========== program output ==========
        == Project Euler: Problem 41 ==

answer: 
=========================*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> primes(int);

#define MAX 100//987654321

int main() {

  vector<int> primez = primes(MAX);
  
  int result = 0;
  
  cout << "\t== Project Euler: Problem 41 ==" << endl << endl; 
  cout << "answer: " << result << endl << endl; 
  
  return 0;
}


//returns all primes from 1 - n ordered from biggest to smallest.
vector<int> primes(max_prime) {

  //vector of bools is said to use 1 bit per bool. Could also use bitset.
  vector<bool> b_prime(max_prime+1, 0);
  
  //sieve is modified to go through only odds.
  for (int i = 3; i <= max_prime; i+=2) {
    b_prime[i] = true;
  }
  
  for (int i = 3; i < sqrt(max_prime)+1; i+=2) {
    if (b_prime[i]) {
      for (int j = 3*i; j < max_prime+1; j+=2*i) {
        b_prime[j] = false; 
      }   
    }
  }
  
  vector<int> primes;
  
  int index = b_prime.length();
  while (index >= 0) {
    if (b_prime[index]) {
      primes.push_back(2*index+3);
      cout << 2*index+3 << endl; 
    }
    index--;  
  }
  
  primes.push_back(2);

  return primes;
}