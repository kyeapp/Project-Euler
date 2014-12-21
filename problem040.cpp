//Kevin Yeap
/*========== Project Euler: Problem 40 ==========
Champernowne's constant
Problem 40
An irrational decimal fraction is created by concatenating the positive integers:

0.123456789101112131415161718192021...

It can be seen that the 12th digit of the fractional part is 1.

If d_n represents the nth digit of the fractional part, find the value of the following expression.

d_1 * d_10 * d_100 * d_1000 * d_10000 * d_100000 * d_1000000
=========================*/

/*========== program design notes ==========
use a vector to store champernowne's constant

store up to 1000000 digits then jut access the digits to find answer

=========================*/

/*========== program output ===========
        == Project Euler: Problem 40 ==

answer: 210
=========================*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define MAX 1000000 //max amount of digits of Champernowne's constant

int find_value();
void calculate_constant(vector<int>& c_const, int next_digit);
int reverse_number(int number);

int main() {
  
  int result = find_value();
  
  cout << "\t== Project Euler: Problem 40 ==" << endl << endl; 
  cout << "answer: " << result << endl << endl; 
  
  return 0;
}

//finds d_1 * d_10 * d_100 * d_1000 * d_10000 * d_100000 * d_1000000
int find_value() {
  vector<int> c_const; // Champernowne's constant
  c_const.push_back(0); //pushing 0 to align number with the array access.
  
  int next_digit = 0; //used to keep track of which digits to add next.
  calculate_constant(c_const, ++next_digit);
  
  int answer = c_const[1] * c_const[10] * c_const[100] * 
               c_const[1000] * c_const[10000] * c_const[100000] * 
               c_const[1000000];
  
 
  return answer;
  
}

//function to find Champernowne's constant up to the MAX digit.
void calculate_constant(vector<int>& c_const, int next_digit) {
  int reverse = reverse_number(next_digit);
  int num_size = log10(next_digit) + 1;
  
  while (num_size > 0) {
    c_const.push_back(reverse%10);
    reverse /= 10; //cut off the last number
    num_size--;
  }
  
  //recursive call to calculate the next digit
  if ( (int)c_const.size() < MAX+1 ) calculate_constant(c_const, ++next_digit);  
}

int reverse_number(int number) {
  int invert = 0;

  while (number != 0) {
    invert = invert * 10;
    invert = invert + number%10;
    number = number/10;
  }

  return invert;
}











