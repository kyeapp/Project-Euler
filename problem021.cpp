//Kevin Yeap
/*========== Project Euler: Problem 21 ==========
Amicable numbers
Problem 21

Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
=========================*/

/*========== program design notes ==========
function to determine if number is amicable
in the amicable function need a function to check for divisible numbers.
another function to cycle through all numbers below 1000.
=========================*/

/*========== program output ==========
        == Project Euler: Problem 21 ==

answer: 31626
=========================*/

#include <iostream>
using namespace std;

int add_amicable(int limit);
int is_amicable(int num);
int divisor_sum(int num);

int main() {
  int limit = 10000;
  int result = add_amicable(limit);
  
  cout << "\t== Project Euler: Problem 21 ==" << endl << endl; 
  cout << "answer: " << result << endl << endl; 
  
  return 0;
}

int add_amicable(int limit) {
  int sum = 0;
  
  for (int i = 1; i < limit; i++) {
    if (is_amicable(i)) { sum += i; }
  }
  return sum;
}

//returns 0 or 1 if the number given is amicable
int is_amicable(int num) {
  int div_sum_num = divisor_sum(num); //store sum of divisors of num in x
  int sum_div_sum = divisor_sum(div_sum_num); //find sum of divisors of x

  if ((num == sum_div_sum) && (div_sum_num != sum_div_sum)) { return 1; }
  return 0;
}

//adds up the sums of num's divisors not including itself
int divisor_sum(int num) {
  int half = num/2;
  int sum = 0;
  
  for (int i = 1; i <= half; i++) {
    if (num%i == 0) { sum += i; }
  }
  return sum;
}
  