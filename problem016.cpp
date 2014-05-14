//Kevin Yeap
/*========== Project Euler: Problem 16 ==========
Power digit sum
Problem 16

215 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 21000?
=========================*/

/*========== program design notes ==========
use bigint library because these numbers too big for me to handle.
=========================*/

/*========== program output ==========
        == Project Euler: Problem 16 ==

answer: 1366
=========================*/

#include <iostream>
#include <cmath>
#include "BigIntegerLibrary.hh"
using namespace std;

BigUnsigned big_pow(BigUnsigned num);
BigUnsigned add_num(BigUnsigned num);

int main() {
  BigUnsigned big_num = big_pow(2);
  BigUnsigned result = add_num(big_num);
  
  cout << "\t== Project Euler: Problem 16 ==" << endl << endl; 
  cout << "answer: " << result << endl << endl; 
  
  return 0;
}

BigUnsigned big_pow(BigUnsigned num) {
  int maxPower = 1000;
  BigUnsigned x(1);
  for (int power = 0; power < maxPower; power++) {
    x *= num; // A BigUnsigned assignment operator
  }
  
  return x;
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