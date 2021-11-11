
<details>
  <summary>fast_pow.go (better)</summary>
<!--START_SECTION:waka-->
	
```go
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
```

<!--END_SECTION:waka-->
</details>	

## Time (without print function)

- fast_exponent_recurse.go
  - 80ms for 1000,000 iteration
  - 50s for 1000,000,000 iteration

- fast_pow.go
  - 28ms for 1000,000 iteration
  - 20s for 1000,000,000 iteration

## Time (with printing)

- fast_exponent_recurse.go
  - 2.0835ms for 1 iteration
  - 15.8835ms for 10 iteration

- fast_pow.go
  - 2.3704ms for 1 iteration
  - 17.6081ms for 10 iteration

| lang | version |
|---|---|
|go|1.16.4 windows/amd64|
