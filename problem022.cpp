//Kevin Yeap
/*========== Project Euler: Problem 22 ==========
Names scores
Problem 22

Using problem022_names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, 
begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value 
by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 
938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?
=========================*/

/*========== program design notes ==========
read in all the names to a vector of strings

Sorting algorithm I am going to use merge sort.
because a few weeks ago I was learning about divide and conquer algorithms 
and because its worst time is O(n log n) guaranteed.

recurrence equation
T(n) = 2T(n/2) + n
E = log_2(2) / log_2(2) = 1.
case 2 of Master Theorem - f(n) ϵ n^E, O(n^E log n) -> O(n log n)

function to return the value of a name.
function to find total name scores.
=========================*/

/*========== program output ==========
        == Project Euler: Problem 22 ==

answer: 871198282
=========================*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void read_to_vector(vector<string>& name_vector);
void merge_sort_names(vector<string>& name_vector);
int name_value(string name);
int total_name_score(vector<string>& name_vector);

int main() {
  vector<string> name_vector;
  
  read_to_vector(name_vector);
  if (!name_vector.empty()) { name_vector.erase(name_vector.begin()); } //remove first element because it is empty.
  merge_sort_names(name_vector);
  
  int result = total_name_score(name_vector);
  
  cout << "\t== Project Euler: Problem 22 ==" << endl << endl; 
  cout << "answer: " << result << endl << endl; 
  
  return 0;
}

//reads all the names of the file into a vector
void read_to_vector(vector<string>& name_vector) {
  string name;
  ifstream input ("problem022_names.txt");

  while(getline(input, name, '"')) {
    if (name[0] != ',') { name_vector.push_back(name); }
  }
}

//sorts the vector of strings in order using merge sort.
void merge_sort_names(vector<string>& name_vector) {
  int half = name_vector.size()/2;
  
  vector<string> subset1(name_vector.begin(), name_vector.begin()+half);
  vector<string> subset2(name_vector.begin()+half, name_vector.end());
  
  //divide partitions in half until there each subset is 1 element in size
  if (subset1.size() > 1) { merge_sort_names(subset1); }
  if (subset2.size() > 1) { merge_sort_names(subset2); }
  
  int a = 0;
  int b = 0;
  int i = 0;
  int s = subset1.size();
  int t = subset2.size();
   
  //merging the two subsets into 1
  while (a < s && b < t) {
    if (subset1[a] < subset2[b]) { 
      name_vector[i] = subset1[a];
      a++; i++;
    } else {
      name_vector[i] = subset2.at(b);
      b++; i++;
    }
  }
  //place the rest of the leftover elements into the array
  while (a < s) {
    name_vector[i] = subset1[a];
    a++; i++;
  }
  while (b < t) {
    name_vector[i] = subset2[b];
    b++; i++;
  }
}

//returns the value of a name
int name_value(string name) {
  int value = 0;
  int i = 0;
  int limit = name.size();
  
  while (i != limit) {
    value += ((int)(name[i]) - 64);
    i++;
  }
  
  return value;
}

int total_name_score(vector<string>& name_vector) {
  int total = 0;
  int limit = name_vector.size();
  
  for (int i = 0; i < limit; i++) {
    total += name_value(name_vector[i]) * (i+1);
    //cout << "name: " << name_vector[i] << " \tposition: " << i+1 << endl; ; 
  }
  
  return total;
}