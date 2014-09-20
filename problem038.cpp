//Kevin Yeap
/*========== Project Euler: Problem 38 ==========
Pandigital multiples
Problem 38
Published on 28 February 2003 at 06:00 pm [Server Time]

Take the number 192 and multiply it by each of 1, 2, and 3:

    192 × 1 = 192
    192 × 2 = 384
    192 × 3 = 576

By concatenating each product we get the 1 to 9 pandigital, 192384576. 
We will call 192384576 the concatenated product of 192 and (1,2,3)

The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, 
giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).

What is the largest 1 to 9 pandigital 9-digit number that can be formed as the 
concatenated product of an integer with (1,2, ... , n) where n > 1?
=========================*/

/*========== program design notes ==========
Need a function to count the number of digits.

by cycling through the numbers my limit would be n = 2;
which means any number bigger than sqrt(987654321) + 1 will not concatenate to 9-digit pandigital
upper limit is 31427
=========================*/

/*========== program output ===========
        == Project Euler: Problem 38 ==

answer: 932718654
=========================*/

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 31427

int largest_pandigital();
bool is_pandigital(int number);
void record(int num, vector<bool>& used);

int main() {
  
  int result = largest_pandigital();
  
  cout << "\t== Project Euler: Problem 38 ==" << endl << endl; 
  cout << "answer: " << result << endl << endl; 
  
  return 0;
}

int largest_pandigital() {
  int largest = 0; //keeps track of the largest found pandigital
  
  for (int c_iter = 1; c_iter < MAX; c_iter++) {
    bool stop = false;
    int n_digits = 0; //number of digits in current concatenation
    int concat = 0; //concatenated number
    int n_temp = 0; //number of digits in the next number to concatenate
    
    for (int i = 1; stop == false; i++) {
      concat += c_iter*i;
      
      n_temp = (int)log10(c_iter*(i+1))+1;
      n_digits = (int)log10(concat);
      
      if ( (n_temp + n_digits) >= 9 ) { stop = true; }
      else { concat *= pow(10, (int)log10(c_iter*(i+1))+1); }
    }
 
    //===has 9 digits=========bigger than largest========is pandigital============
    if (((int)log10(concat)+1 == 9) && (concat > largest) && (is_pandigital((int)concat)) ) {
      largest = concat;
    }
  }
  
  return largest;
}

//function to check if three numbers passed is pandigital 1-9
bool is_pandigital (int number) {
  int num_of_digits = log10(number) + 1;
  
  if ((num_of_digits) != 9) { return false; }
  vector<bool> used(10, false);
  
  record(number, used); //record digits
  
  for (int i = 9; i > 0; i--) {
    if (used[i] == false) { return false; } //if any digit not used return false
  }
  if (used[0]) { return false; } // extra check to see if 0 is used.
  return true;
}

//helper function for checking pandigital
void record(int num, vector<bool>& used) {
  int temp = 0;
  
  while (num != 0) {
    temp = num%10; //get the end digit
    used[temp] = true; //mark it as used
    num = num/10; //chop off the end digit
  }
}