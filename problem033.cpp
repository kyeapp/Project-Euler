//Kevin Yeap
/*========== Project Euler: Problem 33 ==========
Digit canceling fractions
Problem 33

Published on 20 December 2002 at 06:00 pm [Server Time]

The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting 
to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by 
cancelling the 9s.

We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, less than one in 
value, and containing two digits in the numerator and denominator.

If the product of these four fractions is given in its lowest common terms, find the 
value of the denominator.

=========================*/

/*========== program design notes ==========
first try the following to see if it will give us a good result. 

see if the original fraction and the digits of the numerator and denominator multiplied 
together gives us the same result. add one more check that checks that only 3 digits are used.

input size is relatively small so its ok to use two loops for O(n^2) time.

I will be implmenting Euclid's method of finding greatest common factor to find 
reduced fraction form.
=========================*/

/*========== program output ===========
        == Project Euler: Problem 33 ==

answer: 100
=========================*/

#include <iostream>
#include <vector>
using namespace std;

int find_fraction_denom(void);
int p_dig(int number); 
int digits_used(int numer, int denom);
int digits_used(int numer, int denom);
void record(int num, vector<bool>& used);
int gcd(int num1, int num2);

int main() {
  int result = find_fraction_denom();;
  
  cout << "\t== Project Euler: Problem 33 ==" << endl << endl; 
  cout << "answer: " << result << endl << endl; 
  
  return 0;
}

//solves the actual problem.
int find_fraction_denom(void) {
  double o_frac, m_frac; //variables to hold the original fraction and the modified one
  int p_numer = 1; //product of all found numerators
  int p_denom = 1; //product of all found denominators
  
  for (int numer = 11; numer < 100; numer++) {
    for (int denom = numer+1; denom < 100; denom++) {
      o_frac = (double)numer/(double)denom; //store original fraction
      m_frac = (double)p_dig(numer)/(double)p_dig(denom); //store modified fraction
      if ((o_frac == m_frac) && (digits_used(numer, denom) == 3)) { 
        p_numer *= numer;
        p_denom *= denom;
      }
    }
  }
  
  return p_denom/gcd(p_numer, p_denom);
}

//returns the product of the digits in the number passed in.
int p_dig(int number) {
  int result = 1;

  while (number != 0) {
    result *= number%10;
    number = number/10;
  }
  
  return result;
}

int digits_used(int numer, int denom) {
int num_of_digits = 0; //records the number of different digits used in both numerator and denominator
  vector<bool> used(10, false);
  
  record(numer, used);
  record(denom, used);
  for (const auto &i : used) {
    if (i) { num_of_digits += 1; }
  }
  
  return num_of_digits;
}

//helper function of digits_used, it records digits used
void record(int num, vector<bool>& used) {
  int temp = 0;
  
  while (num != 0) {
    temp = num%10; //get the end digit
    used[temp] = true; //mark it as used
    num = num/10; //chop off the end digit
  }
}

//Euclid's method of finding greatest common denominator implementation.
int gcd(int num1, int num2) {
  int bigger = num1; //bigger number of the two
  int smaller = num2; //smaller number of the two numbers
  
  if (num1 < num2) {
    smaller = num1;
    bigger = num2;
  }
  
  if (smaller == 0) { return bigger; } //recursion breaker
  return gcd(smaller, bigger%smaller);
}