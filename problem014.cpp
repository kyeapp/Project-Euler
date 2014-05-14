//Kevin Yeap
/*========== Project Euler: Problem 14 ==========
Longest Collatz sequence
Problem 14

The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.

=========================*/

/*========== program design notes ==========
one function to generate the sequence
another function to loop the sequence for all numbers
=========================*/

/*========== program output ==========
        == Project Euler: Problem 14 ==

answer: 837799
=========================*/

#include <iostream>
using namespace std;

long collatz(long starting_num, long max, long& max_length);
long find_longest_collatz(long limit);

int main() {
  
  
  //long limit = 1000000;
  long limit = 20;
  long result = find_longest_collatz(limit);
  
  cout << "\t== Project Euler: Problem 14 ==" << endl << endl; 
  cout << "answer: " << result << endl << endl; 
  
  return 0;
}

long find_longest_collatz(long limit){
  long max = 0;
  long max_length = 0;
  
  for(long i = 1; i < limit; i++) {
    max = collatz(i, max, max_length);
  }
  
  return max;
}

long collatz(long starting_num, long max, long& max_length) {
  long num = starting_num;
  long seq_length = 0;
  //cout << num << "->";
  
  while (num != 1) {
    if ((num%2) == 0) { num = num/2; }
    else { num = 3*num+1; }
    //cout << num << "->";
    seq_length++;
  }
  seq_length++; //+1 for itself
      
  //cout << endl << endl; 
    
  if (seq_length > max_length) { 
    max_length = seq_length;
    return starting_num; 
  }

  
  return max;
}