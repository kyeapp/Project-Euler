//Kevin Yeap
/*========== Project Euler: Problem 41 ==========
We shall say that an n-digit number is pandigital if it makes use of all the
digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is
also prime.

What is the largest n-digit pandigital prime that exists?
=========================*/

/*========== program design notes ==========
answer is a prime. means that the number is odd.

ways to approach this.
loop through all pandigitals, and filter out primes.
loop through all primes and filter out pandigitals.

it would probably be a better idea to find the primes first since finding
those will also filter out even pandigitals.

sieve of eratosthenes to find primes.
check pandigital starting from the largest prime.

WARNING: since. Go represents a bool in a byte (not a bit).
so with an array of 7654321 bools,this means that the amount of free memory
required to run this program without a runtime error is about 1 GB.

using divisible by 3 rule we can rule out all 8 and 9 digit numbers
=========================*/

/*========== program output ==========
        == Project Euler: Problem 41 ==

answer:7652413
=========================*/

package main

import (
	"fmt"
	"math"
)

const lim = 7654321

func main() {
	var result = find_pandigital_prime(lim)

	fmt.Println("\t== Project Euler: Problem 41 ==\n")
	fmt.Printf("answer: %d", result)
}

func find_pandigital_prime(limit int) int {
	sieve := make([]bool, limit+1, 2*(limit+1))

	//initialize all values to true
	for i := range sieve {
		sieve[i] = true
	}

	//setting up sieve
	sieve[0] = false
	sieve[1] = false

	//set seive limit
	sieve_lim := math.Sqrt(float64(limit))

	//mark off all multiples
	for i := 0; i < int(sieve_lim); i++ {
		if sieve[i] == true {
			mark_multiple(sieve, i)
		}
	}

	//find and return biggest pandigital prime
	for i := len(sieve) - 1; i != 0; i-- {
		if sieve[i] == true && is_pandigital(i) {
			return i
		}
	}

	return -1
}

//function marks off multiples of the bse passed in
func mark_multiple(array []bool, base int) {
	for i := 2; base*i < len(array); i++ {
		array[base*i] = false
	}
}

//checks if a number is pandigital
func is_pandigital(num int) bool {
	prev, curr := 0, 0

	num_size := int(math.Log10(float64(num))) + 1

	for num != 0 {
		curr = prev | (1 << uint(num%10-1))
		if prev == curr || (num%10) > num_size {
			return false
		}
		num = num / 10
		prev = curr
	}

	return true
}
