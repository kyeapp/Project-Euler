//Kevin Yeap
/*========== Project Euler: Problem 15 ==========
Lattice paths
Problem 15

Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

https://projecteuler.net/problem=15

How many such routes are there through a 20×20 grid?
=========================*/

/*========== program design notes ==========
Its easier to solve this problem in terms of probability. since we know we can only go down and right, 
we know we will go down and right 20 times each. And the answer to this question would be, how many ways can
20 rights and 20 downs be ordered? Or how many ways can you place 20 things in 40 spots? 
The answer would be 40 choose 20.
=========================*/

/*========== program output ==========
        == Project Euler: Problem 15 ==

answer: 137846528820
=========================*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double choose(double n, double k);
double fact(double num);

int main() {
  double result = choose(40, 20);
  cout.precision(20);
  
  cout << "\t== Project Euler: Problem 15 ==" << endl << endl; 
  cout << "answer: " << result << endl << endl; 
  
  return 0;
}

//function for nCk. (n choose k)
double choose(double n, double k) {
  return fact(n)/(fact(n-k)*fact(k));
}

//function for factorial
double fact(double num) {
  if (num == 1) return 1;
  return num * fact(num-1);
}