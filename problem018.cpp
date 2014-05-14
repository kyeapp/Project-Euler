//Kevin Yeap
/*========== Project Euler: Problem 18 ==========
Maximum path sum I
Problem 18

By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

   [3]
  [7] 4
 2 [4] 6
8 5 [9] 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below:

              75
             95 64
            17 47 82
           18 35 87 10
          20 04 82 47 65
         19 01 23 75 03 34
        88 02 77 73 07 63 67
       99 65 04 28 06 16 70 92
      41 41 26 56 83 40 80 70 33
     41 48 72 33 47 32 37 16 94 29
    53 71 44 65 25 43 91 52 97 51 14
   70 11 33 28 77 73 17 78 39 68 17 57
  91 71 52 38 17 14 91 43 58 50 27 29 48
 63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route. However, Problem 67, is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o)

=========================*/

/*========== program design notes ==========
find the answer by going through the nodes and keep track of the path to it that is bigger
should end up with as many as paths as number that on the bottom of the triangle. compare all the total cost
at the bottom and that should be the maximum total from top to bottom. this should run in O(n) time since we are only going through
every node once. and its still linear time to check which path is biggest.
=========================*/

/*========== program output ==========
        == Project Euler: Problem 18 ==

answer: 
=========================*/

#include <iostream>
#include <vector>
using namespace std;

class node {
  int x_par;
  int y_par;
  int value;
  int total_value;
};

node::node (int x, int y, int v) {
  x_par = x
  y_par = y;
  value = v;
  total_value = 0;
}

int main() {
  int max_rows = 15;
  vector<vector<node>> triangle; 
  
  triangle.resize(max_rows);

  for (int i = 0; i < max_rows; i++) {
    for (int j = 0; j <= i; j++) {
      triangle[i].resize(j+1);
    }
  }
  
  
 
  int result = 0;
  
  cout << "\t== Project Euler: Problem 18 ==" << endl << endl; 
  cout << "answer: " << result << endl << endl; 
  
  return 0;
}





