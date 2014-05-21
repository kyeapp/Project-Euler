//Kevin Yeap
/*========== Project Euler: Problem 20 ==========
Factorial digit sum
Factorial digit sum
Problem 20

n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
=========================*/

/*========== program design notes ==========
use BIGINTEGER library.
=========================*/

/*========== program output ==========
        == Project Euler: Problem 20 ==

answer: 648
=========================*/

#include <iostream>
#include "BigIntegerLibrary.hh"
using namespace std;

BigUnsigned fact(BigUnsigned num);
BigUnsigned add_num(BigUnsigned num);

int main() {
  
  BigUnsigned num = fact(100);
  
  BigUnsigned result = add_num(num);
  
  cout << "\t== Project Euler: Problem 20 ==" << endl << endl; 
  cout << "answer: " << result << endl << endl; 
  
  return 0;
}

//function for factorial
BigUnsigned fact(BigUnsigned num) {
  if (num == 1) return 1;
  return num * fact(num-1);
}

BigUnsigned add_num(BigUnsigned num) {
  int maxPower = 1000;
  BigUnsigned x(0);
  for (int power = 0; power < maxPower; power++) {
    x += (num%10); // A BigUnsigned assignment operator
      num = num/10;
  }
  
  return x;
}