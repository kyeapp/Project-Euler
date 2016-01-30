//Kevin Yeap
/*========== Project Euler: Problem 42 ==========
The nth term of the sequence of triangle numbers is given by, t_n = ½n(n+1);
so the first ten triangle numbers are:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

By converting each letter in a word to a number corresponding to its
alphabetical position and adding these values we form a word value.
For example,the word value for SKY is 19 + 11 + 25 = 55 = t_10. If the word
value is a triangle number then we shall call the word a triangle word.

Using words.txt (right click and 'Save Link/Target As...'), a 16K text
file containing nearly two-thousand common English words, how many are
triangle words?
=========================*/

/*========== program design notes ==========
the reverse of the triangle number equation is a quadratic equation
you can tell if a number is a triangle value if you use the quadratic formula
equation and the result turns out to be an integer.
=========================*/

/*========== program output ==========
        == Project Euler: Problem 42  ==

answer: 162
=========================*/

package main

import (
	"encoding/csv"
	"fmt"
	"math"
	"os"
)

func handle_err(err error) {
	if err != nil {
		fmt.Println("Error:", err)
		os.Exit(-1)
	}
}

func main() {
	var result = triangle_numbers()

	fmt.Println("\t== Project Euler: Problem 42 ==\n")
	fmt.Printf("answer: %d", result)
}

//counts the number of triangle words
func triangle_numbers() int {
	count := 0
	words := read_csv()

	for i := range words {
		if is_triangle(words[i]) {
			count++
		}
	}

	return count
}

//file is in csv format
func read_csv() []string {
	file, err := os.Open("p042_words.txt")
	handle_err(err)
	defer file.Close()

	reader := csv.NewReader(file)
	decoded_cvs, err := reader.Read()
	handle_err(err)

	return decoded_cvs
}

//determines if the word is a triangle word
func is_triangle(word string) bool {
	word_value := 0

	for i := range word {
		word_value += int(word[i]) - 64
	}

	//triangle number equation reverse is
	//n^2 + n - 2(word_value) = 0

	//quadratic formula form
	//a = 1
	//b = 1
	//c = -2 * word_value

	c := -2 * word_value

	//x is the opposite of b +- the rooooot of b^2 - 4*ac all over 2a,
	//and thats the quadratic formula. da da da da da da da
	quad_form := (-1 + math.Sqrt(float64(1-4*c)))

	if math.Mod(quad_form, 2) == 0 {
		return true
	}

	return false
}
