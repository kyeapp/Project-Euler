//Kevin Yeap
/*========== Project Euler: Problem 4 ==========
Largest palindrome product
Problem 4

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
=========================*/

/*========== program design notes ==========
Need two helper functions.
function one will multiply two 3-digits numbers together.
function two will check if the number resulting from function 1 is a palindrome.

reversing a number:
my first instinct was to convert it into a string and check; 
but after trying to think of a way without strings I came up with a solution where I take log(num)+1 for # of digits
  then use a for loop to reverse number using for( i = (log(num)+1); i > 0; i--) {last digit * 10 * i}
but there is a more clever way to do it. reverse = reverse * 10 + last_digit
  
biggest possible number is 998001 (999 * 999) so we can use int to hold all numbers.

assuming my method of multiplying large numbers in decreasing order and checking if 
they are palindromes once a palindrome is found the number of possible palindrome 
checks decreases. if a palindrome is found. assuming x is a palindrome and x = a * b, where b < a. 
the lower bound which we need to check then becomes a < b. this method works because 
in the case of a * b, the case of number = a * b, where a > b will always be evaluated first,
before it reaches the case of number = b * a.
=========================*/

/*========== program output ==========
        == Project Euler: Problem 4==

answer: 906609
=========================*/

#include <iostream>
using namespace std;

int find_palindrome(void);
int is_palindrome(int num);

int main() {
  
  int result = find_palindrome();
  
  cout << "\t== Project Euler: Problem 4 ==" << endl << endl; 
  cout << "answer: " << result << endl << endl; 
  
  return 0;
}

//finds palindromes by multiplying two 3-digit numbers
int find_palindrome(void) {
  int palindrome = 0;
  int ibound = 0;
  int temp; //temp is the product of the two numbers we are cycling through
  
  //upper bound is largest three digits
  for (int i = 999; i > 99; i--) { //cycle num1
    for(int j = 999; j > 99; j--) { // cycle num2
    temp = i * j;
      if( (temp > palindrome) && (is_palindrome(temp) != 0) ) { //lower bound is palindrome, it only moves up if a palindrome bigger is found 
        palindrome = temp;
        ibound = j;
      }
       //once the number we are cycling reach the lower bound return current biggest palindrome
      if (i < ibound) { return palindrome; }
    }
  }
  return -1; //should never reach here. for debugging only.
}

//if input number is a palindrome it returns it 
int is_palindrome(int num) {
  int temp = num; //temp is the number that is going to get destroyed as reverse is created
  int last_digit;
  int reverse = 0;
  
  //reverse the input number
  while (temp != 0) {
    last_digit = temp%10;
    reverse = reverse * 10 + last_digit;
    temp = temp/10;
  }
  if (num == reverse) { return num; } //return palindrome
  return 0;  //return 0 if no palindrome
}