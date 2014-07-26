//Kevin Yeap
/*========== Project Euler: Problem 36 ==========
Double-base palindromes
Problem 36
Published on 31 January 2003 at 06:00 pm [Server Time]

The decimal number, 585 = 1001001001_2 (binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

(Please note that the palindromic number, in either base, may not include leading zeros.)

=========================*/

/*========== program design notes ==========
check for palindrome numbers first. then check for binary.
use bitset library for binary stuff. technique used to check if binary is palindrome is 
similar to that of reversing a string.
=========================*/

/*========== program output ===========
        == Project Euler: Problem 36 ==

answer: 872187
=========================*/

#include <bitset>
#include <iostream>
#define MAX 1000000 // 1 million 
using namespace std;

int find_doublebase_palindromes(void);
bool is_palindrome_10(int num);
bool is_palindrome_2(int num);

int main() {
  int result = find_doublebase_palindromes();;
  
  cout << "\t== Project Euler: Problem 36 ==" << endl << endl; 
  cout << "answer: " << result << endl << endl; 
  
  return 0;
}

//returns the sum of all doublebased palindrome under 1 million.
int find_doublebase_palindromes(void){
  int total = 0;

  for (int i = 1; i < MAX; i++) {
    if(is_palindrome_10(i) && is_palindrome_2(i)) { total += i; }
  }
  
  return total;
}

//if input number is a palindrome in base 10 it returns true.
bool is_palindrome_10(int num) {
  int temp = num; //temp is the number that is going to get destroyed as reverse is created
  int last_digit;
  int reverse = 0;
  
  //reverse the input number
  while (temp != 0) {
    last_digit = temp%10;
    reverse = reverse * 10 + last_digit;
    temp = temp/10;
  }
  
  if (num == reverse) { return true; } //return true
  return false;  //return false if no palindrome
}

//if input number is a palindrome in base 2 it returns true.
bool is_palindrome_2(int num) {
  bitset<32> binary(num);
  int index1 = 31;
  int index2 = 0; //end of the binary
  
  while(binary[index1] == 0) { index1--; } //skipping leading zeros
  while (index1 > index2) {
    if (binary[index1] != binary[index2]) { return false; }
    index1--;
    index2++;
  }
  
  return true;
}