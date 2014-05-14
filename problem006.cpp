//Kevin Yeap
/*========== Project Euler: Problem 6 ==========
Sum square difference
Problem 6

The sum of the squares of the first ten natural numbers is,
1^2 + 2^2 + ... + 10^2 = 385

The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)^2 = 55^2 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
=========================*/

/*========== program design notes ==========
nothing special about this problem
two helper functions.
function 1: return square of the sum of the first n natural numbers
function 2: return sum of the squares of the first n natural numbers

looks like the square of sum's growth rate is faster that sum of square's
you could say that num of square 
=========================*/

/*========== program output ==========
        == Project Euler: Problem 6 ==

answer: 25164150
=========================*/

#include <iostream>
#include <cmath>
using namespace std;

int square_of_sum(int num);
int sum_of_squares(int num);

int main() {
  
  int number = 100;
  int result = square_of_sum(number) - sum_of_squares(number);
  
  cout << "\t== Project Euler: Problem 6 ==" << endl << endl; 
  cout << "answer: " << result << endl << endl; 
  
  return 0;
}

//returns square of the sum of the first n natural numbers
//ex. (1 + 2 + ... + n)^2
int square_of_sum(int num) {
  int total = 0;
  
  for(int i = 1; i <= num; i++) {
    total += i;
  }
  
  cout << pow(total, 2) << endl; 
  return pow(total, 2);
}
 
//returns square of the sum of the first n natural numbers
//ex. 1^2 + 2^2 + ... + n^2
int sum_of_squares(int num) {
  int total = 0;
  
  for(int i = 1; i <= num; i++) {
    total += pow(i, 2);
  }
  
  cout << total << endl; 
  return total;
}