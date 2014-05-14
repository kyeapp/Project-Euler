//Kevin Yeap
/*========== Project Euler: Problem 5 ==========
Smallest multiple
Problem 5

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
=========================*/

/*========== program design notes ==========
I can think of two approaches to solve this problem. First approach is to start at 20,
increment by 20 until a number divisible by 1 - 20 is found. Second approach is that 
I can take all the prime factors all number 1 - 20 and keep a track of how many of each prime factor
I need to create the lowest common multiple, which should result in the lowest possible number 
divisible by 1 - 20. 

a flaw with this is that the result might be a number bigger than what my variable can hold. 
I will have to test with a smaller number to make sure that my program is working.

I'm not sure which method is faster so I will use the first approach, 
which will be easier to implement.
=========================*/

/*========== program output ==========
        == Project Euler: Problem 5 ==

answer: 232792560
=========================*/

#include <iostream>
using namespace std;

int lcm(int num); 

int main() {
  
  int number = 20;
  int result = lcm(number);
  
  cout << "\t== Project Euler: Problem 5 ==" << endl << endl; 
  cout << "answer: " << result << endl << endl; 
  
  return 0;
}

//returns the lowest common multiple of all number between 1 and input.
int lcm(int num) {
  int test_num = num;
  
  while(1) {
    test_num += num;
    for (int i = num; i > 0; i--) {
      if ( (test_num % i) != 0 ) break;
      if (i == 1) return test_num;
    }                           
  }                              
}

