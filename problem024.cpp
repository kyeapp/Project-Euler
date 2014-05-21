//Kevin Yeap
/*========== Project Euler: Problem 24 ==========
Lexicographic permutations
Problem 24

A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation 
of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, 
we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
=========================*/

/*========== program design notes ==========
discover all numbers in order and push them to a vector. stop at the
millionth number found.

imagine a tree structure and the leaves as the permutations
=========================*/

/*========== program output ==========
        == Project Euler: Problem 24 ==

answer: 2783915460
=========================*/
//takes .8 seconds to run. can be improved?

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void find_permutations(vector<long>& permutations, vector<bool> used, long num, long limit);
bool all_used(vector<bool> used);

int main() {
  
  long digits = 9; //find permutations of numbers 0 - digits
  long limit = 1000000; //what position we need to find of all ordered permutations
  long num = 0;
  vector<long> permutations;
  vector<bool> used;
  used.resize(digits+1);
  fill(used.begin(), used.end(), false);
  
  find_permutations(permutations, used, num, limit); 

 
  long result = permutations[limit-1];
  
  cout << "\t== Project Euler: Problem 24 ==" << endl << endl; 
  cout << "answer: " << result << endl << endl; 
  
  return 0;
}

void find_permutations(vector<long>& permutations, vector<bool> used, long num, long limit) {
  vector<bool> vec_state;
  vec_state = used;
  
  long size = used.size();
  long num_state = num;
  
  long permutations_found = permutations.size();
  
  if (all_used(used)) { permutations.push_back(num); }
  else if (permutations_found < limit){
    for (long i = 0; i < size; i++) {
      if (used[i] == false) {
        used = vec_state; //reset used state back to original.
        num = num_state;  //reset num back to original.
        num = num * 10 + i; //add the number on
        used[i] = true; //set number added to used
        find_permutations(permutations, used, num, limit); //recursive step 
      }
    }
  }
}

bool all_used(vector<bool> used) {
  long size = used.size();
  
  for (long i = 0; i < size; i++) {
    if (!used[i]) return false;
  }
  
  return true;
}