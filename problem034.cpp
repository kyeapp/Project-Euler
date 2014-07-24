//Kevin Yeap
/*========== Project Euler: Problem 34 ==========
Digit factorials
Problem 34
Published on 03 January 2003 at 06:00 pm [Server Time]

145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: as 1! = 1 and 2! = 2 are not sums they are not included.
=========================*/

/*========== program design notes ==========
biggest number will 9999999 any more digits and the factorial sum of digits will always 
be smaller even if all digits are 9.

this is straight forward. loop up to the limit and check for each number.

=========================*/

/*========== program output ===========
        == Project Euler: Problem 34 ==

answer: 40730
=========================*/

#include <iostream>

#define MAX 9999999
using namespace std;

int digit_factorial_sum(void);
int is_digit_factorial(int number);
int factorial(int number);

int main() {
  
  int result = digit_factorial_sum();
  
  cout << "\t== Project Euler: Problem 34 ==" << endl << endl; 
  cout << "answer: " << result << endl << endl; 
  
  return 0;
}

int digit_factorial_sum(void) {
  int total = 0;
  
  for (int i = 3; i < MAX; i++) {
    if (is_digit_factorial(i)) { 
      total += i; 
      //cout << i << endl; 
    }
  }
  
  return total;
}

int is_digit_factorial(int number) {
  int digit_factorial = 0;
  int temp = number;
  
  while (temp != 0) {
    digit_factorial += factorial(temp%10);
    temp = temp/10;
  }
  
  if (digit_factorial == number) { return true; }
  return false;
}

int factorial(int number) {
  if (number == 1 || number == 0) return 1;
  return number*factorial(number-1);
}