//Kevin Yeap
/*========== Project Euler: Problem 17 ==========
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 
115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
=========================*/

/*========== program design notes ==========

=========================*/

/*========== program output ==========
        == Project Euler: Problem 17 ==

answer: 21124
=========================*/

#include <iostream>
#include <cmath>

using namespace std;

int letter_count(int number);
int letter_count_to(int limit);

int main() {
  
  int result = letter_count_to(1000);
  
  cout << "\t== Project Euler: Problem 17 ==" << endl << endl; 
  cout << "answer: " << result << endl << endl; 
  
  return 0;
}

int letter_count_to(int limit){
  int total_l_count = 0;
  
  for (int i = 1; i <= limit; i++) {
    total_l_count += letter_count(i);
  }
  
  return total_l_count; 
}

int letter_count(int number){
  int l_count = 0;
  int dig = 0;
  int num_size = log10(number) + 1;
  
  if (num_size == 1) {
    if (number == 0) { return 0; }
    if (number == 1 || number == 2 || number == 6) { l_count += 3; }    
    else if (number == 4 || number == 5 || number == 9) { l_count += 4; }
    else if (number == 3 || number == 7 || number == 8) { l_count += 5; }
  }
  
  else if(num_size == 2) {
    if (number == 11 || number == 12) { l_count += 6; }    
    else if (number == 15 || number == 16) { l_count += 7; }
    else if (number == 13 || number == 14 || number == 18 || number == 9) { l_count += 8; }
    else if (number == 19) { l_count += 9; }
    else {
      dig = number/10;
      if (dig == 1) { l_count += 3; }
      else if(dig == 4 || dig == 5 || dig == 6) { l_count += 5; }
      else if(dig == 2 || dig == 3 || dig == 8 || dig == 9) { l_count += 6; }
      else if(dig == 7) { l_count += 7; }
      
      l_count += letter_count(number%10);
    }
  }
  
  else if(num_size == 3) {
    l_count += letter_count(number/100) + 7; //+7 for "hundred",
    if (number%100 != 0) { l_count += 3; } //+3 for "and"
    l_count += letter_count(number%100); //pass in last 2 digits
  }
  
  else if(num_size == 4) {
    l_count += letter_count(number/1000) + 8; //+8 for "thousand" 
    l_count += letter_count(number%1000); //pass in first 3 digits
  }
  
  return l_count;
}



