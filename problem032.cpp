//Kevin Yeap
/*========== Project Euler: Problem 32 ==========
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; 
for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, 
and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 
through 9 pandigital.

HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
=========================*/

/*========== program design notes ==========
biggest x or y value should be sqrt(9999) 9999 is the biggest any x or y 
should go and after sqrt(9999) it will start to find products that it has already found.

function to check the three numbers

mergesort the found pandigitals and filter out repeats when adding them up.
=========================*/

/*========== program output ===========
        == Project Euler: Problem 32 ==

answer: 45228
=========================*/

#include <cmath>
#include <iostream>
#include <vector>

#define MAX 100 //this is defined by sqrt(9999)
using namespace std;

int find_pandigital(void);
bool is_pandigital (int x, int y, int z);
void record(int num, vector<bool>& used);
void merge_sort(vector<int>& vec);

int main() {
  int result = find_pandigital();
  
  cout << "\t== Project Euler: Problem 32 ==" << endl << endl; 
  cout << "answer: " << result << endl << endl; 
  
  return 0;
}

//find pandigitals and sums up the products
int find_pandigital(void) {
  int pandigitals_sum = 0;
  int x, y, y_lower, y_upper, z;
  vector<int> pandigitals; //creates vector to store all the pandigitals we found.
  
  for (x = 1; x < MAX; x++) {
    y_upper = pow(10, (5-log10(x))); //biggest y value would be 9999 for z to 
                                     //still have correct amount of digits to be pandigital
    y_lower = pow(10, (int)(((5-log10(x))-1)/10)); //smallest would be 999
    
    for (y = y_lower; y < y_upper; y++) {
      z = x * y;
      if (is_pandigital(x, y, z)) { pandigitals.push_back(z); }
    }
  }
  merge_sort(pandigitals); //sort the found numbers
  
  int prev = 0; 
  for( const auto &i : pandigitals ) { 
    if (i != prev) { pandigitals_sum += i; } //add up non repeating.
	prev = i;
  }

  return pandigitals_sum;
}

//function to check if three numbers passed is pandigital
bool is_pandigital (int x, int y, int z) {
  int a = log10(x) + 1;
  int b = log10(y) + 1;
  int c = log10(z) + 1;
  
  if ((a+b+c) != 9) { return false; }
  vector<bool> used(10, false);
  
  record(x, used); //record digits of all three numbers
  record(y, used);
  record(z, used);
  
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

//a generic merge sort function to help with repeat numbers
void merge_sort(vector<int>& vec) {
  int half = vec.size()/2;
  
  vector<int> subset1(vec.begin(), vec.begin()+half);
  vector<int> subset2(vec.begin()+half, vec.end());
  
  //divide partitions in half until there each subset is 1 element in size
  if (subset1.size() > 1) { merge_sort(subset1); }
  if (subset2.size() > 1) { merge_sort(subset2); }
  
  int a = 0;
  int b = 0;
  int i = 0;
  int s = subset1.size();
  int t = subset2.size();
   
  //merging the two subsets into 1
  while (a < s && b < t) {
    if (subset1[a] < subset2[b]) { 
      vec[i] = subset1[a];
      a++; i++;
    } else {
      vec[i] = subset2[b];
      b++; i++;
    }
  }
  //place the rest of the leftover elements into the array
  while (a < s) {
    vec[i] = subset1[a];
    a++; i++;
  }
  while (b < t) {
    vec[i] = subset2[b];
    b++; i++;
  }
}