//Kevin Yeap
/*========== Project Euler: Problem 39 ==========
Integer right triangles
Problem 39
If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p <= 1000, is the number of solutions maximised?
=========================*/

/*========== program design notes ==========
cycle through p
is_right triangle
find_triangle_solutions
=========================*/

/*========== program output ===========
        == Project Euler: Problem 39 ==

answer: 840
=========================*/

#include <iostream>
using namespace std;

#define MAX 1000 //check perimeter 1 through MAX

int find_max_solutions();
bool is_right_triangle(int a, int b, int c);
int find_triangle_solutions(int permimeter);

int main() {
  
  int result = find_max_solutions();
  
  cout << "\t== Project Euler: Problem 39 ==" << endl << endl; 
  cout << "answer: " << result << endl << endl; 
  
  return 0;
}

//finds the perimeter with the maximum amount of right triangle solutions (rts)
int find_max_solutions(){
  int result = 0; //stores the perimeter with the max amount of rts found
  int rts_i = 0; //stores the number of rts of i;
  int rts_result = 0;
  
  for (int i = 3; i <= MAX; i++) {
    rts_i = find_triangle_solutions(i);
    if (rts_i > rts_result) {
      result = i;
      rts_result = rts_i;
    }
  }

  return result;
}

//returns the number of right triangle solutions given the perimeter passed in
int find_triangle_solutions(int perimeter) {
  int n_solutions = 0; //number of solutions for the perimeter
  int upper_b_bound = 0;
  int c = 0;
  
  for (int a = 1; a < perimeter; a++) {
    upper_b_bound = perimeter - a;
    for (int b = 1; b < upper_b_bound; b++) {
      c = perimeter - a - b;
      if (is_right_triangle(a, b, c)) { n_solutions++; }
    }
  }
  
  return n_solutions/2; //it finds 2 solutions for every 1 because side a and b can be swapped.
}

//returns true if the three numbers passed in creates a right triangle
bool is_right_triangle(int a, int b, int c) {
  if (a*a+b*b == c*c) { return true; }
  return false;
}