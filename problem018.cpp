//Kevin Yeap
/*========== Project Euler: Problem 18 ==========
Maximum path sum I
Problem 18

By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

   [3]
  [7] 4
 2 [4] 6
8 5 [9] 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below:

              75
             95 64
            17 47 82
           18 35 87 10
          20 04 82 47 65
         19 01 23 75 03 34
        88 02 77 73 07 63 67
       99 65 04 28 06 16 70 92
      41 41 26 56 83 40 80 70 33
     41 48 72 33 47 32 37 16 94 29
    53 71 44 65 25 43 91 52 97 51 14
   70 11 33 28 77 73 17 78 39 68 17 57
  91 71 52 38 17 14 91 43 58 50 27 29 48
 63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route. However, Problem 67, is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o)

=========================*/

/*========== program design notes ==========
find the answer by going through the nodes and keep track of the path to it that is bigger
should end up with as many as paths as number that on the bottom of the triangle. compare all the total cost
at the bottom and that should be the maximum total from top to bottom. this should run in O(n) time since we are only going through
every node once. and its still linear time to check which path is biggest.
=========================*/

/*========== program output ==========
        == Project Euler: Problem 18 ==

answer: 
=========================*/

#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;

void parse_triangle(int *triangle_array, string string_triangle, int triangle_space);
int triangle_size(int size);

class node {
  int x_par;
  int y_par;
  int value;
  int total_value;
  
  public:
  node();
  void set_value(int v) { value = v; } 
  void set_total_value(int tval) { total_value = tval; }
  int get_value(void) { return value; }
  int get_total_value(void) { return total_value; }
};

node::node() {
  x_par = 0;
  y_par = 0;
  value = 0;
  total_value = 0;
}

int triangle_size(int size){
  int total = 0;
  for(int i = 1; i <= size; i++) total+=i;
  return total;
}

int main() {
  int max_rows = 15;
  int count = 0;
  int triangle_space = triangle_size(max_rows);
  
  string string_triangle = 
  "75 "
  "95 64 "
  "17 47 82 "
  "18 35 87 10 "
  "20 04 82 47 65 "
  "19 01 23 75 03 34 "
  "88 02 77 73 07 63 67 "
  "99 65 04 28 06 16 70 92 "
  "41 41 26 56 83 40 80 70 33 "
  "41 48 72 33 47 32 37 16 94 29 "
  "53 71 44 65 25 43 91 52 97 51 14 "
  "70 11 33 28 77 73 17 78 39 68 17 57 "
  "91 71 52 38 17 14 91 43 58 50 27 29 48 "
  "63 66 04 68 89 53 67 30 73 16 69 87 40 31 "
  "04 62 98 27 23 09 70 98 73 93 38 53 60 04 23";
  
  int triangle_array[triangle_space]; //hold all the triangle data in an array
  parse_triangle(triangle_array, string_triangle, triangle_space); //converts data_triangle into triangle_array
  vector<vector<node>> triangle; 
  triangle.resize(max_rows);

  //create the triangle data structure
  for (int i = 0; i < max_rows; i++) {
    for (int j = 0; j <= i; j++) {
      triangle[i].resize(j+1);
    }
  }

  //populate the structure
  count = 0;
  for (int i = 0; i < max_rows; i++) {
    for (int j = 0; j <= i; j++) {
      triangle[i][j].set_value(triangle_array[count]);
      count++;
    }
  }
  
  
  //tally pathing cost.
  triangle[0][0].set_total_value(triangle[0][0].get_value());
  for (int i = 0; i < max_rows; i++) {
    for (int j = 0; j <= i; j++) {
      //if node on the left side.
      if ( i != 0 && j == 0) {
        triangle[i][j].set_total_value( triangle[i-1][j].get_total_value() + triangle[i][j].get_value() );
      }
      
      //if node in the middle
      else if (i != 0 && j != i) {
        if (triangle[i-1][j-1].get_total_value() < triangle[i-1][j].get_total_value()) {
          triangle[i][j].set_total_value( triangle[i-1][j].get_total_value() + triangle[i][j].get_value() );
        }else {
          triangle[i][j].set_total_value( triangle[i-1][j-1].get_total_value() + triangle[i][j].get_value() );
        }
      }
      
      //if node on the right side
      else if( i != 0 && j == i ) {
        triangle[i][j].set_total_value( triangle[i-1][j-1].get_total_value() + triangle[i][j].get_value() );
      }
    }
  }
  
  int biggest = 0;
  //find biggest sum of path
  for (int i = 0; i < max_rows; i++) {
    cout << triangle[max_rows-1][i].get_total_value() << "   " << triangle[max_rows-1][i+1].get_total_value() << endl; 
    if (biggest < triangle[max_rows-1][i+1].get_total_value()) {
      biggest = triangle[max_rows-1][i+1].get_total_value();
    }
  }


  
 
  int result = biggest;
  
  cout << "\t== Project Euler: Problem 18 ==" << endl << endl; 
  cout << "answer: " << result << endl << endl; 
  
  return 0;
}

//convert the string into an array of ints
void parse_triangle(int* triangle_array, string string_triangle, int triangle_space) {
  istringstream iss(string_triangle);

  vector<string> tokens;
  copy(istream_iterator<string>(iss),
  istream_iterator<string>(),
  back_inserter<vector<string> >(tokens));

  for (int i = 0; i < triangle_space; i++) {
    triangle_array[i] = stoi(tokens.at(i));
  }
}



