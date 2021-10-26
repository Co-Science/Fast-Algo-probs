package main

import "fmt"

// fast exponent
func Pow(a, b int) int {
	p := 1
	for b > 0 {
		if b&1 != 0 {
			p *= a
		}
		b >>= 1
		a *= a
	}
	return p
}
func main() {
	x := []int{2, 5, 1, 4, 7, 8, 6}
	n := []int{1, 2, 3, 4, 5, 6, 7}
	for i, xi := range x {
		fmt.Println(Pow(xi, n[i]))
	}
}
