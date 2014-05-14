//Kevin Yeap
/*========== Project Euler: Problem 9 ==========
Special Pythagorean triplet
Problem 9

A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a^2 + b^2 = c^2

For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
=========================*/

/*========== program design notes ==========
two parts to this program. 
one part to cycle a and b to find c, increment b every cycle, and check the value of a+b+c.
second part will reset the cycle and increment a by one is a+b+c > 1000. This happens because if we increment b
any more after exceeding 1000 once then all values higher than the current b will result in Pythagorean triple 
with a sum greater than 1000.

I am unsure if I used type-int if there would be a case where it would truncate c to the correct value,
so I will opt to use doubles to store the value to be sure I have the correct values.

I am fairly certain that this program can be faster by incrementing a and b by a factor of n until it goes past a+b+c 
and then decrement by 1 until a+b+c is less than 1000, return if a+b+c == target. This kind of design should
result in a significantly fast program the larger the target sum grows. maybe when I come back and look over these
I will try implementing it.
=========================*/

/*========== program output ==========
        == Project Euler: Problem 9 ==

answer: 31875000
=========================*/

#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;

double find_pythag(int target_sum);

int main() {
  
  double target_sum = 1000;
  double result = find_pythag(target_sum);
  
  cout << "\t== Project Euler: Problem 9 ==" << endl << endl; 
  cout << setprecision(20) << noshowpoint << "answer: " << result << endl << endl;
  
  return 0;
}

//return a*b*c if a+b+c = target_sum.
double find_pythag(int target_sum) {
  double a = 1, b = 1, c = 0;
  
  for (a = 1; (a+1+c) < target_sum; a++) { //1 to simulate the lowest value of b
    for(b = 1; (a+b+c) < target_sum; b++) {
      c = sqrt(pow(a, 2) + pow(b, 2));
      //cout << a << "\t" << b << "\t" << c << endl; 
      if (a+b+c == target_sum) { return a*b*c; }
    }
  }

  return -1; //return -1 if no such values of a, b, c is found.  
}