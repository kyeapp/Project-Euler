//Kevin Yeap
/*========== Project Euler: Problem 43 ==========
The number, 1406357289, is a 0 to 9 pandigital number because it is made up
of each of the digits 0 to 9 in some order, but it also has a rather
interesting sub-string divisibility property.

Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note
the following:

d2 d3 d4=406 is divisible by 2
d3 d4 d5=063 is divisible by 3
d4 d5 d6=635 is divisible by 5
d5 d6 d7=357 is divisible by 7
d6 d7 d8=572 is divisible by 11
d7 d8 d9=728 is divisible by 13
d8 d9 d10=289 is divisible by 17

Find the sum of all 0 to 9 pandigital numbers with this property.
=========================*/

/*========== program design notes ==========
brute force takes about 6 minutes to run. increase the speed by
cycling through permutations.

permutations only takes 3 seconds. acceptable, however can i get it to sub 1 second?

sub 1 second achieved
removed unnecessary code to check for pandigital.
refactored dxxx number filtering from string manipulation to
using modulo


forum notes - interesting potential optimizations read from the forum
build pandigitals backwards and check the first 3 digits for %17 before continuing.
eliminates a great majority of the permutation building.
=========================*/

/*========== program output ==========
        == Project Euler: Problem 43 ==

answer:16695334890
=========================*/

package main

import (
	"fmt"
	"math"
	"os"
)

const (
	digits = 10
)

var (
	bit_full = int(math.Pow(2, digits) - 1)
)

func handle_err(err error) {
	if err != nil {
		fmt.Println("Error:", err)
		os.Exit(-1)
	}
}

func main() {
	var result = pand_sum()

	fmt.Println("\t== Project Euler: Problem 43 ==\n")
	fmt.Printf("answer: %d", result)
}

func pand_sum() int {
	return pand_perm(0, 0)
}

//cycle through pandigitals
func pand_perm(bits int, num int) int {
	sum := 0
	bit_state := bits
	num_state := num

	if bit_state == bit_full {
		if has_div_prop(num) {
			return num
		}
	} else {
		for i := 0; i < digits; i++ {
			if bits&(1<<uint(i)) != (1 << uint(i)) {
				bits = bit_state
				num = num_state
				bits = bits | (1 << uint(i))
				if bits == 1 { //this condition could also be num == 0
					continue
				}

				num = num*10 + i
				sum += pand_perm(bits, num)
			}
		}
	}
	return sum
}

//check if number has desired sub-divisibility property
func has_div_prop(num int) bool {
	/* The only reason case is singled out is because i think this is
	 * the least likely case to succeed and would save on unnecessary
	 * overall calculations, if checked explicitly. this seems to give
	 * about a .1 second speed up. This method has dimishing returns
	 * if stacked.
	 */
	d89x := num % 1000
	if d89x%17 != 0 {
		return false
	}

	num = num / 10
	d789 := num % 1000
	num = num / 10
	d678 := num % 1000
	num = num / 10
	d567 := num % 1000
	num = num / 10
	d456 := num % 1000
	num = num / 10
	d345 := num % 1000
	num = num / 10
	d234 := num % 1000

	if d789%13 != 0 || d678%11 != 0 || d567%7 != 0 ||
		d456%5 != 0 || d345%3 != 0 || d234%2 != 0 {
		return false
	}

	return true
}
