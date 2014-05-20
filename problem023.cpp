//Kevin Yeap
/*========== Project Euler: Problem 23 ==========
Non-abundant sums
Problem 23

A perfect number is a number for which the sum of its proper divisors is exactly 
equal to the number. For example, the sum of the proper divisors of 28 would be 
1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n 
and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number 
that can be written as the sum of two abundant numbers is 24. By mathematical 
analysis, it can be shown that all integers greater than 28123 can be written 
as the sum of two abundant numbers. However, this upper limit cannot be reduced 
any further by analysis even though it is known that the greatest number that 
cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of 
two abundant numbers.
=========================*/

/*========== program design notes ==========
function to determine if number is abundant. O(n).

find all the abundant numbers. O(n).

find all number that can be expressed as sum of two abundant numbers. O(n^2).

answer = sum of all non abundant sums O(n)
=========================*/

/*========== program output ==========
        == Project Euler: Problem 23 ==

answer: 4179871
=========================*/
  
#include <iostream>
#include <vector>
using namespace std;

int divisor_sum(int num);
int is_abundant(int num);
void find_abundant(vector<int>& abundants, int limit);
void find_abundant_sums(vector<bool>& abundant_sums, vector<int>& abundants, int limit);
int sum_of_nonabundant(vector<bool>& abundant_sums);

int main() {
  
  int limit = 28127;//28123; //anything bigger than this number is an abundant sum (of two numbers)
  vector<int> abundants;
  vector<bool> abundant_sums;
  abundant_sums.resize(limit+1);
  fill(abundant_sums.begin(), abundant_sums.end(), false);
  
  find_abundant(abundants, limit);
  find_abundant_sums(abundant_sums, abundants, limit);
  
 
/*
  for (int i = 0; i < abundants.size(); i++) {
    cout << "    " << abundants[i] << endl; 
  }
  
*/
  /*
  for (int i = 0; i < abundant_sums.size(); i++) {
    if (abundant_sums[i]) cout << i << endl; 
  
  }
  */
 
  int result = sum_of_nonabundant(abundant_sums);
  
  cout << "\t== Project Euler: Problem 23 ==" << endl << endl; 
  cout << "answer: " << result << endl << endl; 
  
  return 0;
}

int sum_of_nonabundant(vector<bool>& abundant_sums) {
  int total = 0;
  int size = abundant_sums.size();
  
  for(int i = 0; i < size; i++) {
    if (abundant_sums[i] == false) { total += i; }
  }

  return total;
}

//find numbers that can be expressed as the sum of two abundant numbers
void find_abundant_sums(vector<bool>& abundant_sums, vector<int>& abundants, int limit) {
  int size = abundants.size();
  int temp = 0;
  
  for (int i = 0; i < size; i++) {
    for (int j = i; j < size; j++) {
      temp = abundants[i]+abundants[j];
      if (temp <= limit) { abundant_sums[temp] = true; }
      else break;
    }
  } 
}

//find and stores all abundant numbers in the vector passed in.
void find_abundant(vector<int>& abundants, int limit) {
  for (int i = 1; i <= limit; i++) {
    if (is_abundant(i)) abundants.push_back(i);
  }
}

//returns 1 if the number is abundant
int is_abundant(int num) {
  if (num < divisor_sum(num)) return 1;
  return 0;
}

//adds up the sums of num's divisors not including itself
int divisor_sum(int num) {
  int half = num/2;
  int sum = 0;
  
  for (int i = 1; i <= half; i++) {
    if (num%i == 0) { sum += i; }
  }
  return sum;
}