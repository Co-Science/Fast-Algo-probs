package main

import "fmt"

// general method for fast computation of large positive integer powers of a number,
// or more generally of an element of a semigroup, like a polynomial or a square matrix
func exp_by_squaring(x, n int) int {
	if n < 0 {
		return exp_by_squaring(1/x, -n)
	} else if n == 0 {
		return 1
	} else if n == 1 {
		return x
	} else if n%2 == 0 {
		return exp_by_squaring(x*x, n/2)
	} else if n%2 == 1 {
		return x * exp_by_squaring(x*x, (n-1)/2)
	}
	return -1
}

func main() {
	x := []int{2, 5, 1, 4, 7, 8, 6}
	n := []int{1, 2, 3, 4, 5, 6, 7}
	for i, xi := range x {
		fmt.Println(exp_by_squaring(xi, n[i]))
	}
}
