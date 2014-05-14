//Kevin Yeap
/*========== Project Euler: Problem 1 ==========
Multiples of 3 and 5
Problem 1

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. 
The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.
=========================*/

/*========== program design notes ==========
multiple of 3 and 5 are checked first or else they might be added twice
multiples of 3 are check next because they are more frequent
=========================*/

/*========== program output ==========
        == Project Euler: Problem 1 ==
        
answer: 233168
=========================*/

#include <iostream>
using namespace std;

int add_multiples(int limit);

int main() {
  
  int limit = 1000;  
  int result = add_multiples(limit);

  cout << "\t== Project Euler: Problem 1 ==" << endl << endl; 
  cout << "answer: " << result << endl << endl;

  return 0;
}

int add_multiples(int limit) {
  int total = 0;
  
  for (int i = 0; i < limit; i++) {
    if ((i%15) == 0) total += i;     //check multiples of 15
    else if ((i%3) == 0) total += i; //check multiples of 3
    else if ((i%5) == 0) total += i; //check multiples of 5
  }
  
  return total;
}