Given n integer coordinates. The task is to find sum of manhattan distance between all pairs of coordinates. Manhattan Distance between two points (x1, y1) and (x2, y2) is: |x1 - x2| + |y1 - y2|Examples : 


```
Input : n = 4
        point1 = { -1, 5 }
        point2 = { 1, 6 }
        point3 = { 3, 5 }
        point4 = { 2, 3 }
Output : 22
Distance of { 1, 6 }, { 3, 5 }, { 2, 3 } from 
{ -1, 5 } are 3, 4, 5 respectively.
Therefore, sum = 3 + 4 + 5 = 12

Distance of { 3, 5 }, { 2, 3 } from { 1, 6 } 
are 3, 4 respectively.
Therefore, sum = 12 + 3 + 4 = 19

Distance of { 2, 3 } from { 3, 5 } is 3.
Therefore, sum = 19 + 3 = 22.
```

---
<details>
  <summary>:zap: Method 1: (Brute Force) </summary>
<!--START_SECTION:waka-->
	
Method 1: (Brute Force) 

Time Complexity: O(n2)The idea is to run two nested loop i.e for each each point, find manhattan distance for all other points.  
```
// Go code to find sum of
// Manhattan distance between all
// the pairs of given points

package main

import "fmt"

// Returns the absolute val of the argument
func Abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}

// Return the sum of distance
// between all the pair of points.
func distancesum(x []int, y []int, n int) int {

	sum := 0

	// for each point, finding distance
	// to rest of the point
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			sum += Abs(x[i]-x[j]) + Abs(y[i]-y[j])
		}
	}
	return sum
}

// Driven Code
func main() {

	x := []int{-1, 1, 3, 2}
	y := []int{5, 6, 5, 3}
	n := len(x)
	fmt.Println(distancesum(x, y, n))
}
```

<!--END_SECTION:waka-->
</details>	

---

<details>
  <summary>:zap: Method 2: (Efficient Approach)  </summary>
<!--START_SECTION:waka-->
	


1. The idea is to use Greedy Approach. First observe, the manhattan formula can be decomposed into two independent sums, one for the difference between x coordinates and the second between y coordinates. If we know how to compute one of them we can use the same method to compute the other. So now we will stick to compute the sum of x coordinates distance.
2. Let's assume that we have calculated the sum of distances between any two points till a point xi-1 for all values of x's smaller than xi-1 , let this sum be res and now we have to calculate the distance between any two points with xi included, where xi is the next greater point, To calculate the distance of each point from the next greater point xi ,  we can add the existing sum of differences res with the distance of xi from all the points xk which are less than xi. Hence the sum between any two points will now be equal to res + ∑(xi - xk) , where xi is the current point from which differences are being measured, and xk are all the points less than xi.
3. Because for every calculation xi remains same, we can simplify the summation as :
```
res = res +(xi - x1) + (xi - x2) + (xi - x3).........(xi - xi-1)

res = res + (xi)*i - (x1 + x2 + ...... xi-1) , because in a 
sorted array, there are i elements smaller than the current index i .

res = res + (xi)*i - Si-1  , where Si-1 is the sum of all the 
previous points till index i - 1
```
4. For the new index i , we need to add the difference of the current index xi from all the previous indices xk  < xi

5. If we sort all points in non-decreasing order, we can easily compute the desired sum of distances along one axis between each pair of coordinates in O(N) time, processing points from left to right and using the above method. Also, we don't have to concern if two points are equal coordinates, after sorting points in non-decreasing order, we say that a point xi-1 is smaller xi if and only if it appears earlier in the sorted array.Below is the implementation of this approach: 


<!--END_SECTION:waka-->
</details>

Time Complexity : O(nlogn) 

```
// Go Program to find sum of Manhattan
// distances between all the pairs of
// given points

package main

import (
	"fmt"
	"sort"
)

// Return the sum of distance of one axis.
func distancesum(arr []int, n int) int {

	// sorting the array.
	sort.Ints(arr)

	// for each point, finding the distance.
	res, sum := 0, 0
	for i := 0; i < n; i++ {
		res += (arr[i]*i - sum)
		sum += arr[i]
	}

	return res
}

func totaldistancesum(x []int, y []int, n int) int {
	return distancesum(x, n) + distancesum(y, n)
}

// Driven Program
func main() {

	x := []int{-1, 1, 3, 2}
	y := []int{5, 6, 5, 3}
	n := len(x)

	fmt.Println(totaldistancesum(x, y, n))
}
```
