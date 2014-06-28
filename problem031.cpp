//Kevin Yeap
/*========== Project Euler: Problem 31 ==========
In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:

    1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).

It is possible to make £2 in the following way:

    1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p

How many different ways can £2 be made using any number of coins?

=========================*/

/*========== program design notes ==========
loops through all permutations with constraints based on coin values.
one vector to keep track of coin values. Another vector to keep track of amount of coins
total of coins can only add up to 400p. so the limit for each level of recursion will be based on the 
value of the coin and the total. starting with four-hundred 1p coins and ending with two £2

=========================*/

/*========== program output ===========
        == Project Euler: Problem 31 ==

answer: 73682
=========================*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void push_coins(vector<int>& coins, vector<int>& state);
int coin_sum(vector<int> coins, vector<int> state);
void print_state(vector<int> state);
int find_combination(vector<int> coins, vector<int> state, int index, int value);


int main() {
  
  vector<int> coins; //stores coins that are being used
  vector<int> state; //store current combination state of coins being searched.
  
  push_coins(coins, state);
  
  int index = coins.size()-1;
  int value = 200; //200p == 2£
  int result = find_combination(coins, state, index, value);
  
  cout << "\t== Project Euler: Problem 31 ==" << endl << endl; 
  cout << "answer: " << result << endl << endl; 
  
  return 0;
}

int find_combination(vector<int> coins, vector<int> state, int index, int value){
  if (index == -1) { return 0; }
  int total = 0;
  
  while(coin_sum(coins, state) < value) {
    total += find_combination(coins, state, index-1, value);
    
    state[index]+=1;
  }
  
  if (coin_sum(coins, state) == value) { 
  //print_state(state); 
  total++; }
  
  return total;  
}

int coin_sum(vector<int> coins, vector<int> state) {
  int limit = coins.size();
  int total = 0;
  
  for (int i = 0; i < limit; i++) {
    total += coins[i]*state[i];
  }
  
  
  
  return total;
}

void print_state(vector<int> state) {
  int limit = state.size();
    
  for (int i = 0; i < limit; i++) {
    cout << state[i] << ", ";
  }
  cout << endl; 
}


void push_coins(vector<int>& coins, vector<int>& state) {
  coins.push_back(1);
  coins.push_back(2);
  coins.push_back(5);
  coins.push_back(10);
  coins.push_back(20);
  coins.push_back(50);
  coins.push_back(100);
  coins.push_back(200);
  
  state.resize(coins.size());
  fill(state.begin(), state.end(), 0);
}