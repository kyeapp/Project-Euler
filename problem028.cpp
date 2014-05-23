//Kevin Yeap
/*========== Project Euler: Problem 28 ==========
Number spiral diagonals
Problem 28

Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

[21] 22  23  24 [25]
 20 [07] 08 [09] 10
 19  06 [01] 02  11
 18 [05] 04 [03] 12
[17] 16  15  14 [13]

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
=========================*/

/*========== program design notes ==========
I have observed that starting from the center we only need to add 2 to the number to get the bottom-right, 
add the 2 more for the bottom-left key, add two more for the top-left, and then add two more for the top right.
the we add 4 four times for the next corners, then 6, then 8. we'd only need to add numbers in the right pattern
to get the answer. This can be found in linear time θ(n).
=========================*/

/*========== program output ===========
        == Project Euler: Problem 28 ==

answer: 669171001
=========================*/

#include <iostream>
using namespace std;

int spiral_diagonal_sum(int side_length);

int main() {
  int side_length = 1001;
  int result = spiral_diagonal_sum(side_length);
  
  cout << "\t== Project Euler: Problem 28 ==" << endl << endl; 
  cout << "answer: " << result << endl << endl; 
  
  return 0;
}

//returns the sum of diagonals of a spiral of numbers given size.
int spiral_diagonal_sum(int side_length) {
  int total = 1; //starts at 1 for the center.
  int limit = side_length * side_length;
  int diag = 1; //numbers that land on the diagonal

  for (int i = 2; diag < limit; i+=2) {
    for (int j = 0; j < 4; j++) {
      diag += i;
      total += diag;
      //cout << total << endl; 
    }
  }
  
  return total;
}